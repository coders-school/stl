#include "grays.hpp"

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height> & compress_array)
{
    auto tmp = compress_array[0][0];

    uint8_t count = 0;

    std::vector<std::pair<uint8_t, uint8_t>> vec;
    vec.reserve(width * height);

    for (auto i = 0; i < height; i++)
    {
        for (auto j = 0; j < width; j++)
        {
            if (tmp == compress_array[j][i])
            {
                count++;
            }
            else
            {
                vec.push_back(std::make_pair(tmp, count));
                count = 0;
                tmp = compress_array[j][i];
            }
        }
    }
    return vec;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>> &)
{
    
}