#include "compression.hpp"

#include <algorithm>
#include <iostream>
#include <utility>

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(
    const std::array<std::array<uint8_t, width>, height>& bitmap) {
    std::vector<std::pair<uint8_t, uint8_t>> compressed{};
    int occurrences = 0;
    uint8_t color_code = 0;
    for (const auto& row : bitmap) {
        color_code = *row.begin();
        occurrences = 0;
        for (const auto& element : row) {
            if (element == color_code) {
                ++occurrences;
            } else {
                compressed.emplace_back(std::make_pair(color_code, occurrences));
                color_code = element;
                occurrences = 1;
            }
        }
        compressed.emplace_back(std::make_pair(color_code, occurrences));
    }
    return compressed;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(
    const std::vector<std::pair<uint8_t, uint8_t>>& bitmap) {
    std::array<std::array<uint8_t, width>, height> decompressed{};
    auto it = bitmap.begin();
    int counter = 0;
    for (size_t row = 0; row < height; ++row) {
        for (size_t column = 0; column < width;) {
            while (counter++ < it->second) {
                decompressed[row][column++] = it->first;
            }
            ++it;
            counter = 0;
        }
    }
    return decompressed;
}

void printMap(const std::array<std::array<uint8_t, width>, height>& bitmap) {
    for (const auto& row : bitmap) {
        for (const auto& column : row) {
            if (column <= ' ') {
                std::cout << ' ';
            } else {
                std::cout << column;
            }
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}