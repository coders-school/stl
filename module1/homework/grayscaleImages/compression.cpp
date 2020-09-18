  
#include "compression.hpp"

#include <algorithm>
#include <iostream>
#include <utility>

vector_of_pairs compressGrayscale(const array_of_arrays& bitmap) {
    vector_of_pairs compressed{};
    for (const auto& row : bitmap) {
        for (auto it = row.begin(); it != row.end();) {
            auto findIt = std::adjacent_find(it, row.end(), std::not_equal_to<int>{});
            if (findIt != row.end()) {
                findIt++;
            }
            compressed.emplace_back(*it, std::distance(it, findIt));
            it = findIt;
        }
    }
    return compressed;
}

array_of_arrays decompressGrayscale(const vector_of_pairs& bitmap) {
    array_of_arrays decompressed{};
    auto it = decompressed.front().begin();
    std::for_each(bitmap.begin(), bitmap.end(), [it](const auto& pair) mutable {
        it = std::fill_n(it, pair.second, pair.first);
    });
    return decompressed;
}

void printMap(const array_of_arrays& bitmap) {
    char empty_char = ' ';
    for (const auto& row : bitmap) {
        for (const auto column : row) {
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
