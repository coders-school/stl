#include "compression.hpp"

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height>& bitmap) {
    std::vector<std::pair<uint8_t, uint8_t>> result;

    for (size_t row = 0; row < height; ++row) {
        for (size_t col = 0; col < width;) {
            uint8_t value = bitmap[row][col++];
            uint8_t counter = 1;

            while (col < width && bitmap[row][col] == value) {
                counter++;
                col++;
            }

            result.push_back({value, counter});
        }
    }

    return result;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>> compressed) {
    std::array<std::array<uint8_t, width>, height> decompressed;

    size_t currentIndex = 0;

    for (size_t row = 0; row < height; ++row) {
        for (size_t col = 0; col < width;) {
            uint8_t count = compressed[currentIndex].second;

            while (count > 0 && col < width) {
                decompressed[row][col++] = compressed[currentIndex].first;
                count--;
            }

            if (count == 0) {
                ++currentIndex;
            }
        }
    }

    return decompressed;
}
