#include "compression.hpp"

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, width>, height>& arr){
    std::vector<std::pair<uint8_t, uint8_t>> result;
    result.reserve(width * height);

    for(const auto & i : arr)
    {
        uint8_t element = i.front();
        uint8_t counter = 1;
        for(auto it = cbegin(i) + 1; it != cend(i); ++it)
        {
            if(element != *it)
            {
                result.emplace_back(std::make_pair(element, counter));
                element = *it;
                counter = 1;
                continue;
            }
            counter++;
        }
        result.emplace_back(std::make_pair(element, counter));
    }
    result.shrink_to_fit();
    return result;
}


std::array<std::array<uint8_t, width>, height> decompressGrayscale(const std::vector<std::pair<uint8_t, uint8_t>>& vec)
{
    std::array<std::array<uint8_t, width>, height> result;
    int x = 0;
    int y = 0;
    for(const auto & it : vec)
    {
        std::fill(&result[x][y], &result[x][y + it.second], it.first);
        y += it.second;
        if(y >= width)
        {
            x++;
            y = 0;
        }
    }
    return result;
}
