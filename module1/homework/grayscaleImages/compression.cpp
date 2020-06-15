#include "compression.hpp"

#include <algorithm>
#include <array>
#include <cstdint>
#include <vector>

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height>& fullImage) {
    std::vector<std::pair<uint8_t, uint8_t>> compressedImage;
    compressedImage.reserve(width * height);

    for (size_t i = 0; i < height; ++i) {
        uint8_t current = fullImage[i][0];
        size_t count = 0;

        for (size_t j = 0; j < width; ++j) {
            if (fullImage[i][j] == current) {
                ++count;
            }
            if (fullImage[i][j] != current || j == height - 1) {
                compressedImage.push_back(std::make_pair(current, count));
                current = fullImage[i][j];
                count = 1;
            }
        }
    }
    compressedImage.shrink_to_fit();
    return compressedImage;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>>& compressedImage) {
    std::array<std::array<uint8_t, width>, height> fullImage;

    int row = 0;
    int col = 0;

    for (auto &i : compressedImage) {
        std::fill(&fullImage[row][col], &fullImage[row][col + i.second], i.first);
        col += i.second;
        
        if (col == width - 1) {
            col = 0;
            row++;
        }
    }

    return fullImage;
}
