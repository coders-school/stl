#include "compression.hpp"

#include <iostream>

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height>) {
    return {std::make_pair<uint8_t, uint8_t>(0, 0)};
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(const std::vector<std::pair<uint8_t, uint8_t>>& compressedMap) {
    std::array<std::array<uint8_t, width>, height> decompressed;

    size_t row = 0;
    size_t col = 0;

    for (const auto& [color, count] : compressedMap) {
        for (size_t i = 0; i < count; i++) {
            decompressed[row][col] = color;
            if (col < width - 1) {
                col++;
            } else {
                col = 0;
                row++;
            }
        }
    }

    return decompressed;
}

void printMap(const std::array<std::array<uint8_t, width>, height>& mapToPrint) {
    for (const auto& row : mapToPrint) {
        for (const auto& el : row) {
            std::cout << el;
        }
        std::cout << '\n';
    }
}
