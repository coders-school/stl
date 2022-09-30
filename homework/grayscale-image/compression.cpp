#include "compression.hpp"
#include <iostream>

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height> input) {
    std::vector<std::pair<uint8_t, uint8_t>> pp;

    for (size_t h = 0; h < height; ++h) {
        for (size_t w = 0; w < width; ++w) {
            pp.push_back({0,0});
        }
    }


    return pp;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>> input) {
    std::array<std::array<uint8_t, width>, height> output{};
    return output;
}