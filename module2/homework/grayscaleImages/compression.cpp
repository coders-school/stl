#include "compression.hpp"

#include <algorithm>
#include <iostream>

compressedImage compressGrayscale(const Image& bitmap) {
    compressedImage compressedData;

    compressedData.reserve(width * height);

    for (const auto& row : bitmap) {
        auto current = row.begin();
        while (current != row.end()) {
            uint8_t color = *current;
            auto index = std::find_if(current, row.end(),
                                      [color](uint8_t otherColor) {
                                          return color != otherColor;
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
    Image decompressedData;
    auto it = decompressedData.front().begin();
    std::for_each(compressedBitmap.begin(), compressedBitmap.end(), [it](const auto& pair) mutable {
        it = std::fill_n(it, pair.second, pair.first);
    });
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
