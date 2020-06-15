#include "compression.hpp"

#include <algorithm>
#include <iostream>

compressedImage compressGrayscale(const Image& bitmap) {
    compressedImage compressedData;

    compressedData.reserve(width * height);

    size_t i, j, counter = 1;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width - 1; j++) {
            if (bitmap[i][j] != bitmap[i][j + 1]) {
                compressedData.emplace_back(bitmap[i][j], counter);
                counter = 1;
            } else {
                counter++;
            }
        }
        compressedData.emplace_back(bitmap[i][j], counter);
        counter = 1;
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
