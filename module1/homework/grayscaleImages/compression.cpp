#include "compression.hpp"
#include <forward_list>
#include <iostream>

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height>& bitmap)
{
    std::vector<std::pair<uint8_t, uint8_t>> compression { };

    for(auto it : bitmap)
    {
        compression.emplace_back(std::make_pair(it.front(), 0));
        for(auto it2 : it)
        {
            std::pair<uint8_t, uint8_t>& pair = compression.back();
            if(it2 == pair.first)
            {
                
                pair.second++;
            }
            else
            {
                compression.emplace_back(std::make_pair(it2, 1));
            }
        }
    }

    return compression;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>>& compression)
{
    std::array<std::array<uint8_t, width>, height> bitmap;
    int row = 0;
    int column = 0;

    for(auto it : compression)
    {
        for(auto i = 0; i < it.second; i++)
        {
            bitmap[row][column] = it.first;
            auto t = bitmap[row][column];
            column++;

            if (row == width)
            {
                column = 0;
                row++;
            }
        }    
    }

    return bitmap;
}

void printMap(std::array<std::array<uint8_t, width>, height>& bitmap)
{
    for(auto row : bitmap)
    {
        for(auto element : row)
        {
            element <= ' ' ? std::cout << " " : std::cout << element;
        }

        std::cout << "\n";
    }
}
