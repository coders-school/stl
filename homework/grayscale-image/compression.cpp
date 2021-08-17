#include "compression.hpp"
#include <algorithm>
#include <iostream>

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height> array_in) {
    std::vector<std::pair<uint8_t, uint8_t>> vec;
    uint8_t color = 0;
    uint8_t count = 0;
    for (size_t y = 0; y < height; ++y) {
        color = array_in[y][0];
        count = 0;
        for (size_t x = 1; x <= width; ++x) {
            if (color == array_in[y][x - 1]) {
                ++count;
                if (x == width) {
                    vec.push_back(std::make_pair(color, count));
                }
            } else {
                vec.push_back(std::make_pair(color, count));
                color = array_in[y][x - 1];
                count = 1;
            }
            if ((x == width) && (count == 1)) {
                vec.push_back(std::make_pair(color, count));
            }
        }
    }
    return vec;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>> vec) {
    std::array<std::array<uint8_t, width>, height> array_out;
    uint8_t x = 0;
    uint8_t y = 0;

    for (auto& pair : vec) {
        uint8_t color = pair.first;
        uint8_t count = pair.second;
        for (size_t i = 0; i < count; ++i) {
            if (x < width) {
                array_out[y][x] = color;
                ++x;
                if (x == width) {
                    ++y;
                    x = 0;
                }
            }
        }
    }
    return array_out;
}

void printMap(const std::array<std::array<uint8_t, width>, height>& ninja) {
    for (const auto& elem : ninja) {
        for (const auto& el : elem) {
            if (el < ' ') {
                std::cout << ' ';
            } else {
                std::cout << el;
            }
        }
        std::cout << '\n';
    }
}