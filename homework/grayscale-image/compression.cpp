#include "compression.hpp"
#include <vector>
#include <array>
#include <utility>
#include <cstdint>
#include <iostream>

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, width>, height>& arr) {
    std::vector<std::pair<uint8_t, uint8_t>> vec;
    vec.reserve(width * height);
    uint8_t counter;
    uint8_t lastValue;

    for (const auto& row : arr) {
        lastValue = row.at(0);
        counter = 0;
        for(auto pixel = row.cbegin(); pixel != row.cend(); ++pixel) {
            if (lastValue != *pixel) {
                vec.emplace_back(lastValue, counter);
                counter = 1;
                lastValue = *pixel;
            }
            else if (counter == UINT8_MAX) {
                vec.emplace_back(lastValue, counter);
                counter = 1;
            }
            else {
                ++counter;
            }
            if (pixel + 1 == row.cend()) {
                vec.emplace_back(lastValue, counter);
            }
        }
    }   
    vec.shrink_to_fit();
    return vec;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(const std::vector<std::pair<uint8_t, uint8_t>>& vec) {
    std::array<std::array<uint8_t, width>, height> arr;
    size_t row {0};
    size_t index {0};

    for (const auto& chunk : vec) {
        for (uint8_t i = 0; i < chunk.second; ++i) {
            arr.at(row).at(index) = chunk.first;
            ++index;
        }
        if (index == width) {
            ++row;
            index = 0;
        }
    }
    return arr;
}

void printMap(const std::array<std::array<uint8_t, width>, height>& arr) {
    for(const auto& row : arr) {
        for(const auto& character : row) {
            if(character < 32) {
                std::cout << ' ';
            }
            else {
                std::cout << character;
            }
        }
        std::cout << '\n';
    }
}
