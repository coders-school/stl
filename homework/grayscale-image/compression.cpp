#include <iostream>
#include <array>
#include <vector>
#include "compression.hpp"
#include <utility>

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height>  arr)
{
    std::vector<std::pair<uint8_t, uint8_t>> result;
    if(arr.empty())
    {
        return result;
    }
    for(const auto& el : arr)
    {
        auto value = *(el.begin());
        auto amount = 0;
        for(const auto& item : el)
        {
            if(item == value)
            {
                ++amount;
            }
            else
            {
                result.push_back(std::pair<uint8_t, uint8_t>{value, amount});
                amount = 1;
                value = item;
            }
        }
        result.push_back(std::pair<uint8_t, uint8_t>{value, amount});
    }
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(std::vector<std::pair<uint8_t,     uint8_t>> vec)
{
    std::array<std::array<uint8_t, width>, height> result;
    size_t arrIter = 0;
    size_t lineIter = 0;
    std::array<uint8_t, width> line;
    for(const auto& el : vec)
    {
        for(size_t i = 0; i < std::get<1>(el); ++i, ++lineIter)
        {            
            line[lineIter] = std::get<0>(el);
        }
        if(!(lineIter < width))
        {
            result[arrIter] = line;
            ++arrIter;
            lineIter = 0;
        }
    }
    return result;
}

