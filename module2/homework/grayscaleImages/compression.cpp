#include "compression.hpp"

#include <algorithm>
#include <iostream>
#include <numeric>

Compressed compressGrayscale(const Image& compress) {
    Compressed compressedBitmap;

    int repetitionCounter = 0;
    for (const auto& row : compress) {
        uint8_t actualColor = row.at(0);
        auto lineBegin = row.begin();
        auto lineEnd = row.end();
        while (lineBegin < row.begin() + width) {
            lineEnd = std::find_if(lineBegin, lineEnd,
                                   [actualColor](uint8_t color) {
                                       return actualColor != color;
                                   });
            repetitionCounter = std::distance(lineBegin, lineEnd);
            if (repetitionCounter == 0) {
                repetitionCounter = 1;
            }
            compressedBitmap.push_back({actualColor, repetitionCounter});
            std::advance(lineBegin, repetitionCounter);
            std::advance(lineEnd, width - repetitionCounter);
            actualColor = *lineBegin;
        }
    }
    compressedBitmap.shrink_to_fit();
    return compressedBitmap;
}

Image decompressGrayscale(const Compressed& compressedMap) {
    if (std::accumulate(compressedMap.cbegin(), compressedMap.cend(), 0, [](auto sum, const auto& pair) {
            return sum + pair.second;
        }) > width * height) {
        return {};
    }

    Image decompressed;

    auto row = decompressed.begin();
    auto col = row->begin();

    std::for_each(compressedMap.cbegin(), compressedMap.cend(), [&](const auto& pair) {
        if (col >= row->end()) {
            std::advance(row, 1);
            col = row->begin();
        }
        std::fill_n(col, pair.second, pair.first);
        std::advance(col, pair.second);
    });

    return decompressed;
}

void printMap(const Image& mapToPrint) {
    for (const auto& row : mapToPrint) {
        for (const auto el : row) {
            if (el <= ' ') {
                std::cout << ' ';
            } else {
                std::cout << el;
            }
        }
        std::cout << '\n';
    }
}
