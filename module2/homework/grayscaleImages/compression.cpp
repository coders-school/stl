#include "compression.hpp"

#include <algorithm>
#include <iostream>
#include <iterator>

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(
    const std::array<std::array<uint8_t, width>, height>& bitmap) {
    std::vector<std::pair<uint8_t, uint8_t>> compressed_bitmap;
    for (const auto& element : bitmap) {
        for (auto it = element.begin(); it != element.end();) {
            auto itDifferent = std::find_if_not(it, element.end(), [it](auto recent) {
                return *it == recent;
            });

            compressed_bitmap.push_back({*it, std::distance(it, itDifferent)});
            it = itDifferent;
        }
    }
    return compressed_bitmap;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(
    const std::vector<std::pair<uint8_t, uint8_t>>& compressed_bitmap) {
    std::array<std::array<uint8_t, width>, height> decompressed_bitmap;
    auto it = decompressed_bitmap.front().begin();
    std::for_each(compressed_bitmap.begin(), compressed_bitmap.end(), [&it](auto pair) {
        it = std::fill_n(it, pair.second, pair.first);
    });

    return decompressed_bitmap;
}

void printMap(const std::array<std::array<uint8_t, width>, height>& decompressed_bitmap) {
    for (const auto& row : decompressed_bitmap) {
        for (const auto& ch : row) {
            if (ch < min_printable) {
                std::cout << ' ';
            } else {
                std::cout << ch;
            }
        }
        std::cout << '\n';
    }
}
