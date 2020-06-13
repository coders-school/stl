#include "compression.hpp"

#include <iostream>

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, width>, height>& arrayToCompress) {
    std::vector<std::pair<uint8_t, uint8_t>> compressedBitmap;

    int counter = 0;
    uint8_t color = 0;

    for (const auto row : arrayToCompress) {
        color = row.front();
        counter = 0;

        for (const auto column : row) {
            if (column == color) {
                ++counter;
            } else {
                compressedBitmap.emplace_back(color, counter);
                counter = 1;
                color = column;
            }
        }
        compressedBitmap.emplace_back(color, counter);
    }

    return compressedBitmap;
}
std::array<std::array<uint8_t, width>, height> decompressGrayscale(const std::vector<std::pair<uint8_t, uint8_t>>& compressedBitmap) {
    std::array<std::array<uint8_t, width>, height> decompressedBitmap;

    size_t row = 0;
    size_t column = 0;

    for (const auto [color, counter] : compressedBitmap) {
        if (row < height) {
            for (size_t i = 0; i < counter; ++i) {
                decompressedBitmap[row][column] = color;
                if (column < width - 1) {
                    ++column;
                } else {
                    column = 0;
                    ++row;
                }
            }
        }
    }
    return decompressedBitmap;
}

void printMap(std::array<std::array<uint8_t, width>, height>& bitmap) {
    uint8_t notPrintableSigns = ' ';

    for (const auto& row : bitmap) {
        for (const auto& column : row) {
            if (column <= notPrintableSigns) {
                std::cout << notPrintableSigns;
            } else {
                std::cout << column;
            }
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}