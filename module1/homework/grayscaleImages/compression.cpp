#include "compression.hpp"

#include <algorithm>
#include <array>
#include <iostream>
#include <utility>
#include <vector>

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height>& bitmap) {
    std::vector<std::pair<uint8_t, uint8_t>> compressedData;
    compressedData.reserve(width * height);

    for (const auto& row : bitmap) {
        if (row.empty())
            continue;

        uint8_t prevElem = row.front();
        uint8_t cnt = 1;

        for (auto it = row.begin(); it != row.end(); it++) {
            if (*it == prevElem && it != row.begin()) {
                cnt++;
            }
            if (*it != prevElem || it == std::prev(row.end())) {
                compressedData.emplace_back(std::make_pair(prevElem, cnt));
                cnt = 1;
            }
            prevElem = *it;
        }
    }

    compressedData.shrink_to_fit();

    return compressedData;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>>& compressedData) {
    std::array<std::array<uint8_t, width>, height> bitmap;
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

void printMap(std::array<std::array<uint8_t, ninjaWidth>, ninjaHeight>& bitmap) {
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
