#include "compression.hpp"
#include <algorithm>

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height> input)
{
    std::vector<std::pair<uint8_t, uint8_t>> vec;

    std::for_each(input.begin(), input.end(),
        [&vec](auto tab) mutable
        {
            auto position = tab.begin();
            int count = 0;
            int val = 0;

            for(;position != tab.end();)
            {
                val = *position;
                auto upper = std::find_if (position, tab.end(), [i{*position}](auto a){ return a != i;});
                count = std::distance(position, upper);
                //std::fill_n(std::back_inserter(vec), 1, std::pair<uint8_t, uint8_t>{val, count});
                vec.push_back(std::pair<uint8_t, uint8_t>{val, count});
                count = 0;
                position = upper;
            }
        }
    ); 

    return vec;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>> vec)
{
    std::array<std::array<uint8_t, width>, height> arr;

    auto it_vec = vec.begin();

    std::for_each(arr.begin(), arr.end(),
        [&it_vec](auto& tab) mutable
        {
            auto it1_arr = tab.begin();
            auto it2_arr = tab.begin();
            for(;it2_arr != tab.end();)
            {
                std::advance(it2_arr, it_vec->second);
                std::fill(it1_arr, it2_arr, it_vec->first);
                it_vec++;
                it1_arr = it2_arr;
            }
            return tab;
        }
    );
    return arr;
}
