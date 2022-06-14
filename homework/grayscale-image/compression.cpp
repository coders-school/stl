#include "compression.hpp"

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height> input)
{
    // std::vector<std::pair<uint8_t, uint8_t>> vec;
    // for (size_t i = 0; i < input.size(); i++)
    // {
    //     auto start = 0;
    //     int count = 0;
    //     int val = 0;
    //     int tmp = 0;
    //     while (start < input[0].size() - 1)
    //     {
    //         val = input[i][start];
    //         count++;
    //         while (start < width - 1)
    //         {
    //             start++;
    //             if (input[i][start] == val)
    //             {
    //                 count++;
    //                 if (start == input[0].size() - 1)
    //                 {
    //                     break;
    //                 }
    //             }
    //             else
    //             {
    //                 vec.push_back(std::pair<uint8_t, uint8_t>{val, count});
    //                 count = 0;
    //                 break;
    //             }
    //         }
    //     }
    //     if (start == width -1 && count == 0)
    //     {
    //         val = input[i][start];
    //         vec.push_back(std::pair<uint8_t, uint8_t>{val, 1});
    //     }
    //     else
    //     {
    //         vec.push_back(std::pair<uint8_t, uint8_t>{val, count});
    //     }

    // }
    // return vec;

    std::vector<std::pair<uint8_t, uint8_t>> vec;

    std::for_each(input.begin(), input.end(),
        [&vec](auto tab) mutable
        {
            auto position = tab.begin();
            int count = 0;
            int val = 0;

            while (position != tab.end())
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
    int start = 0;
    int stop = 0;
    int sum = 0;
    for (size_t k = 0; k < arr.size(); k++)
    {
        while (sum < width)
        {
            sum += vec[stop].second;
            stop++;
        }
        std::array<uint8_t, width> tmp;
        int begin = 0;
        for (int i = start; i < stop; i++)
        {
            for (size_t j = begin; j < begin + vec[i].second; j++)
            {
                tmp[j] = vec[i].first;
            }
            begin += vec[i].second;
        }
        arr[k] = tmp;
        sum = 0;
        start = stop;
    }
    return arr;
}
