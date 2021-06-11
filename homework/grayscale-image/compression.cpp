#include "compression.hpp"

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, width>, height>& image)
{
    std::vector<std::pair<uint8_t, uint8_t>> result{};

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


std::array<std::array<uint8_t, width>, height> decompressGrayscale(const std::vector<std::pair<uint8_t, uint8_t>>& compressed_image)
{
    std::array<std::array<uint8_t, width>, height> decompressed_image{};
    size_t n = 0;
    size_t m = 0;

    for (auto& row : compressed_image)
    {
        for (size_t j = 0; j < row.second; ++j)
        {
            decompressed_image.at(n).at(m) = row.first;
            m++;

            if (m >= width)
            {
                n++;
                m = 0;
            }

            if (n >= height)
            {
                break;
            }
        }
    }
    return decompressed_image;
}