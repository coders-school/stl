#include "compression.hpp"
#include <iostream>

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height> &compress_array)
{

    std::vector<std::pair<uint8_t, uint8_t>> vec;
    vec.reserve(width * height);
    
    for (const auto &el : compress_array)
    {
        uint8_t tmp = el.front();
        uint8_t count = 0;

        for (auto j = el.cbegin(); j < el.cend(); j++)
        {
            if (tmp != *j)
            {
               vec.push_back(std::make_pair(tmp, count));
                tmp = *j;
                count = 1;
            }
            else
            {
                count++;
            }
            if (j + 1 == el.cend())
            {
                vec.push_back(std::make_pair(tmp, count));
            }
            
        }
    }
    vec.shrink_to_fit();
    return vec;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>> &decompress)
{

    std::array<std::array<uint8_t, width>, height> arr;

    auto column = 0;
    auto row = 0;

    for (const auto &pair : decompress)
    {
        for (uint8_t i = 0; i < pair.second; i++)
        {
            arr.at(row).at(column) = pair.first;
            column++;
        }
        if (column == width)
        {
            row++;
            column = 0;
        }
    }

    return arr;
}
