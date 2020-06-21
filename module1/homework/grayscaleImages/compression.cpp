#include "compression.hpp"

#include <algorithm>
#include <forward_list>
#include <iostream>
#include <iterator>

compressedImage compressGrayscale(const image& bitmap) {
    compressedImage compression;
    compression.reserve(width * height);

    for (const auto& row : bitmap) {
        for (auto it = row.begin(); it != row.end();) {
            auto newIt = std::adjacent_find(it, row.end(), [](auto a, auto b) { return a != b; });
            if (newIt != row.end()) {
                std::advance(newIt, 1);
            }
            compression.emplace_back(*it, std::distance(it, newIt));
            it = newIt;
        }
    };

    compression.shrink_to_fit();
    return compression;
}

image decompressGrayscale(const compressedImage& compression) {
    image bitmap;
    auto it = bitmap.front().begin();
    std::for_each(compression.begin(), compression.end(), [it](const auto& pair) mutable {
        it = std::fill_n(it, pair.second, pair.first);
    });
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
