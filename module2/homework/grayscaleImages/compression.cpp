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
    result.reserve(width * height);

    std::for_each(std::cbegin(line), std::cend(line), [&result, &line](uint8_t pixel) {
        if (!result.empty() and result.back().first == pixel)
        {
            result.back().second++;
        }
        else
        {
            result.push_back(std::make_pair(pixel, 1));
        }
    });

    result.shrink_to_fit();
    return result;
}

CompressedBitmap compressGrayscale(const Bitmap& bitmap)
{
    CompressedBitmap result;
    result.reserve(width);
    CompressedBitmap tmp;
    tmp.reserve(width);

    std::for_each(std::begin(bitmap), std::end(bitmap), [&tmp, &result](const auto& line)
    {
        tmp = compressLine(line);
        result.insert(std::end(result), std::begin(tmp), std::end(tmp));
    });
    result.shrink_to_fit();
    return result;
}

Bitmap decompressGrayscale(const CompressedBitmap& compressedBitmap)
{
    Bitmap result;
    auto iter = std::begin(result.front());
    std::for_each(std::begin(compressedBitmap), std::end(compressedBitmap), [&result, &iter] (const auto& group)
    {
        iter = std::fill_n(iter, group.second, group.first);
    });
    return result;
}
