#include "compression.hpp"

#include <algorithm>
#include <iostream>

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, width>, height>& compress) {
    std::vector<std::pair<uint8_t, uint8_t>> compressedBitmap;

    int repetitionCounter = 0;
    uint8_t color = 0;

    for (const auto& row : compress) {
        color = row.front();
        repetitionCounter = 0;
        for (auto column : row) {
            if (column == color) {
                ++repetitionCounter;
            } else {
                compressedBitmap.emplace_back(color, repetitionCounter);
                color = column;
                repetitionCounter = 1;
            }
        }
        compressedBitmap.emplace_back(color, repetitionCounter);
    }

    return compressedBitmap;
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
