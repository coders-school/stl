#include <array>
#include <cstdint>
#include <iostream>
#include <utility>
#include <vector>

#include "compression.hpp"

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height> picture) {
    std::vector<std::pair<uint8_t, uint8_t>> compressedPicutre;

    for (const auto& row : picture) {
        auto it = row.begin();
        auto count = 1;
        for (const auto& el : row) {
            auto number = *it;
            if (++it != row.end() && *it == number) {
                ++count;
            } else {
                compressedPicutre.emplace_back(number, count);
                count = 1;
            }
        }
    }
    return compressedPicutre;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>> picture) {
    std::array<std::array<uint8_t, width>, height> decompressedPicture;
    std::size_t rowNumber = 0;
    std::size_t columnNumber = 0;
    for (const auto& vectorPair : picture) {
        for (int i = vectorPair.second; i > 0; i--) {
            decompressedPicture[rowNumber][columnNumber] = vectorPair.first;
            ++columnNumber;
        }
        if (columnNumber == width) {
            columnNumber = 0;
            ++rowNumber;
        }
    }
    return decompressedPicture;
}

void printMap(std::array<std::array<uint8_t, width>, height> picture) {
    for (const auto& row : picture) {
        for (const auto& el : row) {
            std::cout << el;
        }
        std::cout << '\n';
    }
}