#include "compression.hpp"

#include <algorithm>
#include <iomanip>
#include <iostream>

using Bitmap = std::array<std::array<uint8_t, width>, height>;
using CompressedBitmap = std::vector<std::pair<uint8_t, uint8_t>>;

void printMap(const Bitmap &bitmap)
{
    for (const auto &line : bitmap)
    {
        for (const auto c : line)
        {
            if (c < ' ')
            {
                std::cout << ' ';
            }
            else
            {
                std::cout << c;
            }
        }
        std::cout << '\n';
    }
}

CompressedBitmap compressGrayscale(const Bitmap &bitmap)
{
    CompressedBitmap compressed;

    for (const auto &line : bitmap)
    {
        auto firstElemIter = line.cbegin();
        auto lastElemIter = firstElemIter;

        do
        {
            lastElemIter = std::find_if(firstElemIter, line.cend(), [firstElemIter](uint8_t i) {
                return i != *firstElemIter;
            });
            compressed.push_back({*firstElemIter, std::distance(firstElemIter, lastElemIter)});
            firstElemIter = lastElemIter;

        } while (firstElemIter != line.cend());
    }
    return compressed;
}

Bitmap decompressGrayscale(const CompressedBitmap &compressed)
{
    Bitmap decompressed;
    auto row = 0;
    auto column = 0;

    for (auto chunk : compressed)
    {
        std::fill_n(&decompressed[row][column], chunk.second, chunk.first);
        column += chunk.second;
        if (column >= width)
        {
            row++;
            column = 0;
        }
    }
    return decompressed;
}
