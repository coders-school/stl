#include "compression.hpp"
#include <algorithm>
#include <iostream>
#include <iomanip>

void printMap (std::array<std::array<uint8_t, width>, height> bitmap)
{
    for(const auto& line : bitmap)
    {
        for (const auto c : line)
        {
            std::cout<<std::setw(3)<<(int)c<<' ';

        }
        std::cout<<'\n';
    }
}

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale (std::array<std::array<uint8_t, width>, height> bitmap)
{
    std::vector<std::pair<uint8_t, uint8_t>> compressed;

    for (const auto& line : bitmap)
    {
        auto firstElemIter = line.cbegin();
        auto lastElemIter = firstElemIter;

        do
        {
            lastElemIter = std::find_if( firstElemIter, line.cend(), [firstElemIter](uint8_t i) {
                return i != *firstElemIter;
            });
            compressed.push_back({*firstElemIter, std::distance(firstElemIter, lastElemIter)});
            firstElemIter = lastElemIter;

        } while(firstElemIter != line.cend());
    }
    return compressed;
}


//TODO
std::array<std::array<uint8_t, width>, height> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>> compressed)
{
    std::array<std::array<uint8_t, width>, height> decompressed;

    return decompressed;
}
