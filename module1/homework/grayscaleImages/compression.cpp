#include "compression.hpp"

#include <forward_list>
#include <iostream>

compressedImage compressGrayscale(const image& bitmap) {
    compressedImage compression;

    for (auto& it : bitmap) {
        compression.emplace_back(std::make_pair(it.front(), 0));
        for (auto it2 : it) {
            std::pair<uint8_t, uint8_t>& pair = compression.back();
            if (it2 == pair.first) {
                pair.second++;
            } else {
                compression.emplace_back(std::make_pair(it2, 1));
            }
        }
    }

    return compression;
}

image decompressGrayscale(const compressedImage& compression) {
    image bitmap;
    int row = 0;
    int column = 0;

    for (auto it : compression) {
        for (auto i = 0; i < it.second; i++) {
            bitmap[row][column] = it.first;
            auto t = bitmap[row][column];
            column++;

            if (row == width) {
                column = 0;
                row++;
            }
        }
    }

    return bitmap;
}

void printMap(const image& bitmap) {
    for (auto row : bitmap) {
        for (auto element : row) {
            if (std::iscntrl(element)) {
                std::cout << " ";
            } else {
                std::cout << element;
            }
        }
        std::cout << "\n";
    }
}
