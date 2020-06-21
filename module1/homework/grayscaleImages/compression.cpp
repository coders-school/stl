#include "compression.hpp"

#include <iomanip>
#include <iostream>
#include <sstream>

std::vector<std::pair<uint8_t, uint8_t>>  compressGrayscale(const std::array<std::array<uint8_t, width>, height>& img) {
    std::vector<std::pair<uint8_t, uint8_t>>  bitMap;
    bitMap.reserve(height * width);

    for (const auto& row : img) {
        uint8_t consecutiveCount = 0;

        for (uint8_t i = 0; i < width; i++) {
            consecutiveCount++;
            if (i == width - 1 or row[i + 1] != row[i]) {
                bitMap.emplace_back(std::make_pair(row[i], consecutiveCount));
                consecutiveCount = 0;
            }
        }
    }
    bitMap.shrink_to_fit();
    return bitMap;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(const std::vector<std::pair<uint8_t, uint8_t>>& compressedImg) {
    std::array<std::array<uint8_t, width>, height> decompressed;

    auto currentEmptySlot = decompressed[0].begin();

    for (const auto& pair : compressedImg) {
        auto placeToFillTo = std::next(currentEmptySlot, pair.second);
        std::fill(currentEmptySlot, placeToFillTo, pair.first);
        currentEmptySlot = placeToFillTo;
    }

    return decompressed;
}

void printMap(const std::array<std::array<uint8_t, width>, height>& img) {
    std::stringstream ss;
    for (const auto& row : img) {
        for (const uint8_t pixel : row) {
            ss << (char)(isprint(pixel) ? pixel : ' ');
        }
        ss << '\n';
    }
    std::cout << ss.str();
}
