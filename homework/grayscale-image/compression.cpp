#include "compression.hpp"

std::vector<std::pair<uint8_t, uint8_t>>
compressGrayscale(const std::array<std::array<uint8_t, width>, height>& image) {
    std::vector<std::pair<uint8_t, uint8_t>> result;
    for (size_t i = 0; i < height; i++) {
        uint8_t count = 1;
        uint8_t prevColor = 0;
        for (size_t j = 0; j < width; j++) {
            if (j == 0) {
                prevColor = image[i][j];
            } else {
                if (prevColor != image[i][j]) {
                    result.push_back(std::make_pair(prevColor, count));
                    count = 1;
                    prevColor = image[i][j];
                } else {
                    count++;

                }
            }
        }
        result.push_back(std::make_pair(prevColor, count));
    }
    return result;
}
