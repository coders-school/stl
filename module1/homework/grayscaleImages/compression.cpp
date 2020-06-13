#include "compression.hpp"

#include <algorithm>
#include <iostream>

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height>& bitmap) {
    std::vector<std::pair<uint8_t, uint8_t>> output;
    std::vector<uint8_t> v(width * height);

    for (auto& line : bitmap) {
        uint8_t counter = 1;
        uint8_t color = line.front();

        for (size_t i = 1; i < line.size(); i++) {
            if (color == line[i]) {
                counter++;
            } else {
                output.emplace_back(std::make_pair(color, counter));
                counter = 1;
                color = line[i];
            }
        }

        output.emplace_back(std::make_pair(color, counter));
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
