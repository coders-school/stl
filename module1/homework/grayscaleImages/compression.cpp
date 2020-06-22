#include "compression.hpp"

#include <algorithm>
#include <iostream>

CompressedPGM compressGrayscale(BitmapPGM& bitmap) {
    CompressedPGM output;

    for (const auto& line : bitmap) {
        for (auto color = line.begin(); color != line.end();) {
            auto nextColor = std::adjacent_find(color, line.end(), std::not_equal_to<int>{});
            if (nextColor != line.end()) {
                nextColor++;
            }
            output.emplace_back(*color, std::distance(color, nextColor));
            color = nextColor;
        }
    }
    return output;
}

BitmapPGM decompressGrayscale(CompressedPGM& compressedBitmap) {
    BitmapPGM bitmap;
    auto it = bitmap.front().begin();

    for (auto [color, count] : compressedBitmap) {
        std::fill_n(it, count, color);
        std::advance(it, count);
    }

    return bitmap;
}

void printMap(BitmapPGM& bitmap) {
    std::string colors = " .:-=+*#%@";
    for (auto& line : bitmap) {
        for (auto color : line) {
            std::cout << colors[char(color * colors.size() / UINT8_MAX)] << " ";
        }
        std::cout << '\n';
    }
}
