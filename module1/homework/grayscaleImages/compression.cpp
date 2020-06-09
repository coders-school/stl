#include "compression.hpp"
#include <iostream>

void printMap(Bitmap bitmap)
{
    for (const auto& line : bitmap)
    {
        for (const auto& pixel : line)
        {
            std::cout << pixel;
        }
        std::cout << "\n";
    }
}

CompressedBitmap compressLine(const std::array<uint8_t, width>& line)
{
    CompressedBitmap result;
    std::pair<uint8_t, uint8_t> buffer{line[0], 0};

    for (const auto& pixel : line)
    {
        if (buffer.first == pixel)
        {
            buffer.second++;
            buffer.first = pixel;
        }
        else
        {
            result.push_back(buffer);
            buffer.first = pixel;
            buffer.second = 1;
        }
    }
    result.push_back(buffer);
    return result;
}

CompressedBitmap compressGrayscale(Bitmap bitmap)
{
    CompressedBitmap result;
    CompressedBitmap tmp;

    for (const auto& line : bitmap)
    {
        tmp = compressLine(line);
        result.insert(std::end(result), std::begin(tmp), std::end(tmp));
    }
    return result;
}

Bitmap decompressGrayscale(const CompressedBitmap compressedBitmap)
{
    Bitmap result;
    std::array<uint8_t, width>::iterator iter = std::begin(result[0]);
    for (const auto& group : compressedBitmap)
    {
        iter = std::fill_n(iter, group.second, group.first);
    }
    return result;
}
