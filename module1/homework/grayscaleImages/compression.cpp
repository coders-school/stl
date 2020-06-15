#include "compression.hpp"

#include <algorithm>
#include <iostream>
#include <numeric>

Compressed compressGrayscale(const Image& compress) {
    Compressed compressedBitmap;

    uint8_t repetitionCounter = 0;

    for (const auto row : compress) {
        repetitionCounter = 1;
        for (auto color = row.begin(); color != row.end(); ++color) {
            auto nextColor = std::next(color);
            if (*color != *nextColor || nextColor == row.end()) {
                compressedBitmap.emplace_back(*color, repetitionCounter);
                repetitionCounter = 1;
            } else {
                repetitionCounter++;
            }
        }
    }
    compressedBitmap.shrink_to_fit();
    return compressedBitmap;
}

Image decompressGrayscale(const Compressed& compressedMap) {
    if (std::accumulate(compressedMap.cbegin(), compressedMap.cend(), 0, [](auto sum, const auto& pair) {
            return sum + pair.second;
        }) > width * height) {
        return {};
    }

    Image decompressed;

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
        for (const auto el : row) {
            if (el <= ' ') {
                std::cout << ' ';
            } else {
                std::cout << el;
            }
        }
        std::cout << '\n';
    }
}
