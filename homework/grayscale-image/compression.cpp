#include "compression.hpp"
#include <algorithm>
#include <array>
#include <iostream>
#include <utility>
#include <vector>

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, width>, height>& arr) {
    std::vector<std::pair<uint8_t, uint8_t>> vec;
    vec.reserve(width * height);
    std::for_each(arr.cbegin(), arr.cend(), [&vec](const auto& row) {
        auto it = vec.end();
        std::transform(row.cbegin(), row.cend(), std::back_inserter(vec), [](const auto& pixel) {
            return std::make_pair(pixel, 1);
        });
        while (it != vec.end()){
        it = std::adjacent_find(it, vec.end(), [](const auto& a, const auto& b) { return a.first == b.first; });
            if (it != vec.end()) {
                ++(it->second);
                vec.erase(it + 1);
            }
        }
    });
    vec.shrink_to_fit();
    return vec;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(const std::vector<std::pair<uint8_t, uint8_t>>& vec) {
    std::array<std::array<uint8_t, width>, height> arr;
    size_t row{0};
    size_t index{0};

    for (const auto& chunk : vec) {
        for (uint8_t i = 0; i < chunk.second; ++i) {
            arr.at(row).at(index) = chunk.first;
            ++index;
            if (index == width) {
                ++row;
                index = 0;
            }
        }
    }
    return arr;
}

void printMap(const std::array<std::array<uint8_t, width>, height>& arr) {
    constexpr uint8_t charactersToDisregard{31};
    for (const auto& row : arr) {
        for (const auto& character : row) {
            if (character <= charactersToDisregard) {
                std::cout << ' ';
            } else {
                std::cout << character;
            }
        }
        std::cout << '\n';
    }
}
