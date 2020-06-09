#include "compression.hpp"

#include <algorithm>
#include <iostream>
#include <numeric>

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
    if (std::accumulate(compressedMap.cbegin(), compressedMap.cend(), 0, [](auto sum, const auto& pair) {
            return sum + pair.second;
        }) > width * height) {
        return {};
    }

    std::array<std::array<uint8_t, width>, height> decompressed;

    auto row = decompressed.begin();
    auto col = row->begin();

    std::for_each(compressedMap.cbegin(), compressedMap.cend(), [&](const auto& pair) {
        if (col >= row->end()) {
            std::advance(row, 1);
            col = row->begin();
        }
        std::fill_n(col, pair.second, pair.first);
        std::advance(col, pair.second);
    });

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
