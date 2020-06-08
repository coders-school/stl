#include "compression.hpp"

#include <iostream>

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, width>, height>& bitmap) {
    std::vector<std::pair<uint8_t, uint8_t>> compressed;
    for (const auto& line : bitmap) {
        uint8_t count{};
        uint8_t pixel = line.at(0);
        for (const auto& el : line) {
            if (pixel == el) {
                ++count;
            } else {
                compressed.push_back(std::make_pair(pixel, count));
                count = 1;
                pixel = el;
            }
        }
        compressed.push_back(std::make_pair(pixel, count));
    }

    return compressed;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(const std::vector<std::pair<uint8_t, uint8_t>>& compressed) {
    std::array<std::array<uint8_t, width>, height> bitmap;

    size_t count{}, line{}, el{};
    for (const auto& pair : compressed) {
        if (count >= width) {
            count = 0;
            el = 0;
            ++line;
        }
        for (int i = 0; i < pair.second; ++i) {
            bitmap[line][el] = pair.first;
            ++el;
        }
        count += pair.second;
    }

    return bitmap;
}

void printMap(const std::array<std::array<uint8_t, width>, height>& bitmap) {
    for (const auto& line : bitmap) {
        for (const auto& el : line) {
            if(el <= ' ') {
                std::cout << ' ';
            } else {
                std::cout << el;
            }
        }
        std::cout << '\n';
    }
}
