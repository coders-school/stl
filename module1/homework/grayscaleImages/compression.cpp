#include "compression.hpp"

#include <iostream>

void printMap(const bitmapArr& bitmap) {

    for (const auto& arr : bitmap) {
        for (auto el : arr) {
            if (iscntrl(el))
                std::cout << " ";
            else
                std::cout << el;
        }
        std::cout << "\n";
    }
}

grayScaleVec compressGrayscale(const bitmapArr& grayScale) {

    grayScaleVec compressed;
    compressed.reserve(width * height);
    uint8_t count = 0;

    for (const auto& row : grayScale) {
        auto prev = row.front();
        for (auto column : row) {
            if (prev == column) {
                count++;
                prev = column;
                continue;
            }
            compressed.push_back({prev, count});
            prev = column;
            count = 1;
        }
        compressed.push_back({prev, count});
        count = 0;
    }

    compressed.shrink_to_fit();

    return compressed;
}

bitmapArr decompressGrayscale(const grayScaleVec& compressed) {

    bitmapArr decompressed;
    int i = 0;
    int j = 0;

    for (const auto& pair : compressed) {
        for (int count = 0; count < pair.second; count++, j++)
            decompressed[i][j] = pair.first;
        if (j == width) {
            i++;
            j = 0;
        }
    }

    return decompressed;
}
