#include "compression.hpp"

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, width>, height>& bitmap) {
    
    std::vector<std::pair<uint8_t, uint8_t>> vec;
    uint8_t color;
    uint8_t count;

    for (size_t i = 0; i < height; i++) {
        for (size_t j = 0; j < width; j++) {
            if (j == 0) {
                color = bitmap[i][j];
                count = 1;
            } else if (color == bitmap[i][j]) {
                count++;
            } else {
                vec.push_back(std::make_pair(color, count));
                color = bitmap[i][j];
                count = 1;
            }
        }
        vec.push_back(std::make_pair(color, count));
    }

    return vec;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(const std::vector<std::pair<uint8_t, uint8_t>>& compressed) {
    
    std::array<std::array<uint8_t, width>, height> bitmap;
    size_t i{0};
    size_t j{0};

    for (const auto & pair : compressed) {
        for (size_t k = j; k < (j + pair.second); k++) {
            bitmap[i][k] = pair.first;
        }
        j += pair.second;
        if (j == (width - 1)) {
            i++;
        }
    }
    
    return bitmap;
}

