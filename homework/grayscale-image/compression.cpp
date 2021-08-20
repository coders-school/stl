#include "compression.hpp"

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height> &uncompressed)
{
    std::vector<std::pair<uint8_t, uint8_t>> compressed;
    compressed.reserve(width * height);
    for (const auto &row : uncompressed)
    {
        auto colour = row.front();
        uint8_t counter = 0;
        auto it = row.cbegin();
        //for (auto it = row.cbegin(); it < row.cend(); it++) 
        for(size_t i {0}; i < width; i++)
        {
            if(colour != *it)
            {
                compressed.push_back(std::make_pair(colour, counter));
                colour = *it;
                counter = 1;
            }
            else
            {
                counter++;
            }
            if(it + 1 == row.cend())
            {
                compressed.push_back(std::make_pair(colour, counter));
            }
            std::advance(it, 1);
        }
    }
    compressed.shrink_to_fit();
    return compressed;
}


std::array<std::array<uint8_t, width>, height> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>> &compressed)
{
    std::array<std::array<uint8_t, width>, height> uncompressed;

    auto column = 0;
    auto row = 0;

    for (const auto &pair : compressed)
    {
        for (auto i = 0; i < pair.second; i++)
        {
            uncompressed[row][column] = pair.first;
            column++;
        }
        if (column == width)
        {
            row++;
            column = 0;
        }
    }

    return uncompressed;
}