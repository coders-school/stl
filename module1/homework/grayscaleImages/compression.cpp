#include "compression.hpp"
#include <iostream>

void printMap(const Bitmap& bitmap)
{
    for (const auto line : bitmap)
    {
        for (const auto pixel : line)
        {
            std::cout << pixel;
        }
        std::cout << "\n";
    }
}

CompressedBitmap compressLine(const std::array<uint8_t, width>& line)
{
    CompressedBitmap result;
    result.reserve(width*height);

    for (const auto pixel : line)
    {
        if(!result.empty() and result.back().first == pixel)
        {
            result.back().second++;
        }
        else
        {
            result.push_back(std::make_pair(pixel,1));
        }
    }

    result.shrink_to_fit();
    return result;
}

CompressedBitmap compressGrayscale(const Bitmap& bitmap)
{
    CompressedBitmap result;
    result.reserve(width);
    CompressedBitmap tmp;
    tmp.reserve(width);

    for (const auto& line : bitmap)
    {
        tmp = compressLine(line);
        result.insert(std::end(result), std::begin(tmp), std::end(tmp));
    }
    result.shrink_to_fit();
    return result;
}

Bitmap decompressGrayscale(const CompressedBitmap& compressedBitmap)
{
    Bitmap result;
    auto iter = std::begin(result.front());
    for (const auto& group : compressedBitmap)
    {
        iter = std::fill_n(iter, group.second, group.first);
    }
    return result;
}
