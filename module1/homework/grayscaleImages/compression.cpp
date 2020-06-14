#include "compression.hpp"

#include <iostream>

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, width>, height>& arr) {
    std::vector<std::pair<uint8_t, uint8_t>> vec;
    uint8_t count;
    uint8_t current;
    for (const auto& el1 : arr) {
        count = 0;
        current = el1.at(0);
        for (const auto& el2 : el1) {
            if (current == el2) {
                count++;
            } else {
                vec.push_back(std::make_pair(current, count));
                count = 1;
                current = el2;
            }
        }
        vec.push_back(std::make_pair(current, count));
    }
    return vec;
}
std::array<std::array<uint8_t, width>, height> decompressGrayscale(const std::vector<std::pair<uint8_t, uint8_t>>& vec) {
    std::array<std::array<uint8_t, width>, height> arr;
    uint8_t count;
    uint8_t current = 0;
    for (const auto& el1 : vec) {
        if (count >= width) {
            count = 0;
            ++current;
        }
        for (size_t i = count; i < count + el1.second; i++) {
            arr[current][i] = el1.first;
        }
        count += el1.second;
    }

    return arr;
}

void printMap(const std::array<std::array<uint8_t, width>, height>& printMap) {
    for (const auto& el1 : printMap) {
        for (const auto& el2 : el1) {
            std::cout << el2;
        }
        std::cout << '\n';
    }
}