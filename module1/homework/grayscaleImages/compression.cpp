#include <algorithm>
#include <iostream>
#include <utility>

#include "compression.hpp"

std::vector<uint8_tPair> compressGrayscale(bitmapType& bitmap) {
    std::vector<uint8_tPair> compressedData;
    compressedData.reserve(width * height);

    for (const auto& row : bitmap) {
        uint8_t prevElem = row.front();
        uint8_t cnt = 1;

        for (auto it = row.begin(); it != row.end(); it++) {
            if (*it == prevElem && it != row.begin()) {
                cnt++;
            }
            if (*it != prevElem || it == std::prev(row.end())) {
                compressedData.emplace_back(prevElem, cnt);
                cnt = 1;
            }
            prevElem = *it;
        }
    }

    compressedData.shrink_to_fit();

    return compressedData;
}

compressedArray decompressGrayscale(std::vector<uint8_tPair>& compressedData) {
    compressedArray bitmap;
    auto rowNum = 0;
    int pos = 0;
    std::array<uint8_t, width> row;

    for (const auto& elem : compressedData) {
        std::fill_n(std::next(row.begin(), pos), elem.second, elem.first);
        pos += elem.second;

        if (pos >= width) {
            bitmap[rowNum++] = row;
            pos = 0;
        }
    }
    return bitmap;
}

void printMap(imageBitmap& bitmap) {
    for (const auto& row : bitmap) {
        for (const auto& c : row) {
            if (std::iscntrl(c))
                std::cout << " ";
            else
                std::cout << c;
        }
        std::cout << '\n';
    }
}
