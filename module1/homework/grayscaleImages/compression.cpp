#include "compression.hpp"

#include <cctype>
#include <iostream>

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(
    const std::array<std::array<uint8_t, width>, height>& bitmap) {
    std::vector<std::pair<uint8_t, uint8_t>> compressedBitmap{};

    for (const auto& el : bitmap) {
        compressedBitmap.push_back(std::make_pair(*begin(el), 1));
        for (auto iter = std::next(begin(el)); iter != end(el); ++iter) {
            if (*iter == compressedBitmap.back().first) {
                compressedBitmap.back().second++;
            } else {
                compressedBitmap.push_back(std::make_pair(*iter, 1));
            }
        }
    }
    return compressedBitmap;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(
    const std::vector<std::pair<uint8_t, uint8_t>>& compressedBitmap) {
    std::array<std::array<uint8_t, width>, height> decompressedBitmap{};

    size_t i = 0;
    size_t j = 0;

    for (const auto& el : compressedBitmap) {
        for (size_t k = 0; (k < el.second) && (j < width); ++k, ++j) {
            decompressedBitmap[i][j] = el.first;
        }
        if (j == width) {
            if (++i == height) {
                break;
            }
            j = 0;
        }
    }

    return decompressedBitmap;
}

void printMap(const std::array<std::array<uint8_t, width>, height>& bitmap) {
    for (const auto& row : bitmap) {
        for (const auto el : row) {
            if (std::isprint(el)) {
                std::cout << el;
            } else {
                std::cout << ' ';
            }
        }
        std::cout << '\n';
    }
}
