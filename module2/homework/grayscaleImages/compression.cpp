#include "compression.hpp"

#include <algorithm>
#include <iostream>

ccompressedImage compressGrayscale(const Image& bitmap) {
    compressedImage compressedData;

    compressedData.reserve(width * height);

    for (const auto& row : bitmap) {
        auto current = row.begin();
        while (current != row.end()) {
            uint8_t color = *current;
            auto index = std::find_if_not(current, row.end(),
                                      [color](uint8_t otherColor) {
                                          return color == otherColor;
                                      });
            auto counter = std::distance(current, index);
            compressedData.push_back({color, counter});
            current = index;
        }
    }

    compressedData.shrink_to_fit();

    return compressedData;
}

Image decompressGrayscale(const compressedImage& compressedBitmap) {
    uint8_t currWidth = 0, row = 0;
    Image decompressedData;

    for (const auto& el : compressedBitmap) {
        for (size_t i = currWidth; i < currWidth + el.second; i++) {
            decompressedData[row][i] = el.first;
        }
        currWidth += el.second;
        if (currWidth == width) {
            currWidth = 0;
            row++;
        }
    }

    return decompressedData;
}

void printMap(const Image& bitmap) {
    for (const auto& row : bitmap) {
        for (const auto px : row) {
            if (px <= printable_limit) {
                std::cout << printable_limit;
            } else {
                std::cout << px;
            }
        }
        std::cout << "\n";
    }
}
