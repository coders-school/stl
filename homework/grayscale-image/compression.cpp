#include "compression.hpp"

std::vector<std::pair<uint8_t, uint8_t>> 
compressGrayscale(std::array<std::array<uint8_t, width>, height> arr)
{
    std::vector<std::pair<uint8_t, uint8_t>> vec {};
    size_t cnt{1};

    for(auto it = arr.begin(); it != arr.end(); ++it)
    {
        for(auto jt = it->begin(); jt != it->end(); ++jt)
        {
            if(jt == it->end()-1 || *jt != *(jt+1))
            {
                vec.push_back(std::make_pair(*jt, cnt));
                cnt = 1;
            }
            else
            {
                ++cnt;
            }
        }
    }

    return vec;
}

std::array<std::array<uint8_t, width>, height>
decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>> vec)
{
    std::array<std::array<uint8_t, width>, height> out_arr {};

    size_t sum{}, row{}, col{};
    for(auto const& el : vec)
    {
        sum += el.second;
        for(uint8_t cnt = 0; cnt<el.second; ++cnt)
        {
            out_arr[row][col++] = el.first;
        }

        if(sum == width)
        {
            sum = 0;
            col = 0;
            if(++row > height) break;
        }
    }

    return out_arr;
}
