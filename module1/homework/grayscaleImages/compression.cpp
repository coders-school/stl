#include "compression.hpp"

#include <algorithm>
#include <iostream>
#include <utility>

using vector_of_pairs = std::vector<std::pair<uint8_t, uint8_t>>;
using array_of_arrays = std::array<std::array<uint8_t, width>, height>;

vector_of_pairs compressGrayscale(const array_of_arrays& bitmap) {
    vector_of_pairs compressed{};
    uint8_t occurrences = 0;
    uint8_t color_code = 0;
    for (const auto& row : bitmap) {
        color_code = row.front();
        occurrences = 1;
        for (auto element = row.begin(); element != row.end(); ++element) {
            if (color_code != *std::next(element) || std::next(element) == row.end()) {
                compressed.emplace_back(std::make_pair(color_code, occurrences));
                color_code = *std::next(element);
                occurrences = 1;
            } else {
                ++occurrences;
            }
        }
        // for (auto element : row) {

        // }
        // compressed.emplace_back(std::make_pair(color_code, occurrences));
    }
    compressed.shrink_to_fit();
    return compressed;
}

array_of_arrays decompressGrayscale(const vector_of_pairs& bitmap) {
    array_of_arrays decompressed{};
    auto it = bitmap.begin();
    int counter = 0;
    for (size_t row = 0; row < height; ++row) {
        for (size_t column = 0; column < width;) {
            while (counter++ < it->second) {
                decompressed[row][column++] = it->first;
            }
            ++it;
            counter = 0;
        }
    }
    return decompressed;
}

void printMap(const array_of_arrays& bitmap) {
    char empty_char = ' ';
    for (const auto& row : bitmap) {
        for (const auto& column : row) {
            if (column == empty_char) {
                std::cout << empty_char;

            } else {
                std::cout << column;
            }
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}
