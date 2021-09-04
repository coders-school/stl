#include "compress.hpp"
#include <iostream>
#include <array>
#include <algorithm>
#include <utility>

uint8_t ActualColor = 0 ;
uint8_t counter = 0;
int licznikRzedu = 0;


std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(Fracton arr)
{
    std::vector<std::pair<uint8_t, uint8_t>> result {};
    
    for (size_t i = 0; i < height; i++)
    {
        result.push_back(std::make_pair(ActualColor, counter));
        counter = 0;
        for (size_t j = 0; j < width; j++)
        {
            if (j == 0)
            {
                ActualColor = arr[i][j];
                counter++;
            }
            else
            {
                if (ActualColor == arr[i][j])
                {
                   counter++;
                }
                else
                {
                    result.push_back(std::make_pair(ActualColor, counter));

                    ActualColor = arr[i][j];
                    counter = 1;
                }
            }
        }
    }
 

 
    return result;
}


void printMap(const std::array<std::array<uint8_t, width>, height>& arr) {
    const uint8_t lowestChar{31};
    for (const auto& row : arr) {
        for (const auto& character : row) {
            if (character <= lowestChar) {
                std::cout << ' ';
            } else {
                std::cout << character;
            }
        }
        std::cout << '\n';
    }
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(const std::vector<std::pair<uint8_t, uint8_t>> &compressed)
{
    std::array<std::array<uint8_t, width>, height> decompressed;
    auto it = begin(decompressed)->begin();
    std::for_each(compressed.begin(), compressed.end(), [&it](auto pair) {
                                                                std::fill_n(it, pair.second, pair.first);
                                                                it = std::next(it, pair.second); });
    return decompressed;
}