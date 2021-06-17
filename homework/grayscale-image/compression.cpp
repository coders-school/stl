#include "compression.hpp"
#include <iostream>

void DebugPrint(std::vector<std::pair<uint8_t, uint8_t>> &vec)
{
    for (auto &el : vec)
    {
        std::cout << el.first << " | " << el.second << "\n";
    }
}

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale (std::array<std::array<uint8_t, width>, height> &bitmap)
{
    std::vector<std::pair<uint8_t, uint8_t>> compressedBitmap;
    compressedBitmap.reserve(width*height);
    for(const auto &el : bitmap)
    {
        uint8_t colour = el.front();
        uint8_t counter = 0;
        std::cout << colour;
        for (auto i = el.begin(); i < el.end(); i++)
        {
            if (colour != *i)
            {
                compressedBitmap.push_back(std::make_pair(colour, counter));
                colour = *i;
                counter = 1;
            }
            else
            {
                counter++;
            }
            if (i + 1 == el.end())
            {
                compressedBitmap.push_back(std::make_pair(colour, counter));
            }
            
        }
    }
    compressedBitmap.shrink_to_fit();
    return compressedBitmap;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale (std::vector<std::pair<uint8_t, uint8_t>>&){
    
}