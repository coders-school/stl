#include "compression.hpp"

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, 240>, 160> image)
{
    std::vector<std::pair<uint8_t, uint8_t>> result(256);

    for (size_t i = 0; i < image.size(); ++i)
    {
        result.push_back(std::pair<uint8_t, uint8_t>(image[i][0], 1));
        for (size_t j = 1;j < image.at(i).size(); ++j)
        {
            if (image[i][j] == result.back().first)
            {
                result.back().second++;
            }
            else
            {
                result.push_back(std::pair<uint8_t, uint8_t>(image[i][j], 1));
            }
        }
        
    }
    return result;
}


std::array<std::array<uint8_t, 240>, 160>decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>>)
{
    return {};
}