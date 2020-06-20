#include "compression.hpp"

#include <algorithm>
#include <iostream>

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height>& bitmap) {
    std::vector<std::pair<uint8_t, uint8_t>> output;
    std::vector<uint8_t> v(width * height);

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

std::array<std::array<uint8_t, width>, height> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>>& data) {
    std::array<std::array<uint8_t, width>, height> bitmap;
    auto it = bitmap[0].begin();

    for (auto [color, count] : data) {
        std::fill_n(it, count, color);
        std::advance(it, count);
    }

    return bitmap;
}

void printMap(std::array<std::array<uint8_t, width>, height>& bitmap) {
    std::string colors = " .:-=+*#%@";
    for (auto& line : bitmap) {
        for (auto color : line) {
            std::cout << colors[char(color * colors.size() / UINT8_MAX)] << " ";
        }
        std::cout << '\n';
    }
}
