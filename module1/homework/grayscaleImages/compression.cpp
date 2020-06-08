#include "compression.hpp"

#include <algorithm>
#include <iostream>
#include <map>

compressedBitmap compressGrayscale(const image& img) {
    compressedBitmap cb{};

    for (const auto& row : img) {
        cb.emplace_back(std::make_pair(0, 0));
        for (const auto col : row) {
            if (cb.back().first != col) {
                cb.emplace_back(std::make_pair(col, 1));
            } else {
                ++cb.back().second;
            }
        }
    }
    cb.shrink_to_fit();

    return cb;
}

image decompressGrayscale(const compressedBitmap& cBmp) {
    image reconstructedImage{};

    auto bitmapPair = cBmp.begin();
    auto counter = 0;

    for (size_t row = 0; row < height; ++row) {
        for (size_t col = 0; col < width;) {  // TODO: Maybe it can be replaced with inner while loop
            const auto [value, count] = *bitmapPair;
            while (counter++ < count) {
                reconstructedImage[row][col++] = value;
            }
            bitmapPair++;
            counter = 0;
        }
    }

    return reconstructedImage;
}

void printMap(const image& img) {
    for (const auto& row : img) {
        for (const auto col : row) {
            if (col <= ' ') {
                std::cout << ' ';
            } else {
                std::cout << col;
            }
        }
        std::cout << '\n';
    }
}
