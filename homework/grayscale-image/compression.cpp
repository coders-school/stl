#include <iostream>
#include "compression.hpp"

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height>& bitmap) {
    std::vector<std::pair<uint8_t, uint8_t>> compressvec;
    compressvec.reserve(width * height);
   
    for (const auto& element : bitmap) {
        uint8_t collor_value  = element.front();
        uint8_t counter = 0;

        for (auto pix = element.cbegin(); pix < element.cend(); pix++) {
            if (collor_value != *pix) {
                compressvec.push_back(std::make_pair(collor_value, counter));
                collor_value = *pix;
                counter = 1;
            }
            else
            {
                counter++;
            }
            if (pix + 1 == element.cend())
            {
                compressvec.push_back(std::make_pair(collor_value, counter));
            }

        }
    }

    compressvec.shrink_to_fit();
    return compressvec;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>>& compress) {
    std::array<std::array<uint8_t, width>, height> decompressarray;

    auto x = 0;
    auto y = 0;

    for (const auto& pair : compress)
    {
        for (uint8_t i = 0; i < pair.second; i++)
        {
            decompressarray.at(y).at(x) = pair.first;
            x++;
        }
        if (x == width)
        {
            y++;
            x = 0;
        }
    }

    return decompressarray;
}
