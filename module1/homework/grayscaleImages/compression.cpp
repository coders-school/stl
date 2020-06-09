#include "compression.hpp"

#include <iostream>

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(
    const std::array<std::array<uint8_t, width>, height>& bitmap) {
    std::vector<std::pair<uint8_t, uint8_t>> compressed_bitmap;
    for (uint8_t i = 0; i < height; ++i) {
        uint8_t sequence_begin = 0;
        for (uint8_t j = 0; j < width; ++j) {
            if (j == width -1 || bitmap[i][j] != bitmap[i][j + 1]) {
                compressed_bitmap.push_back(
                    std::make_pair(bitmap[i][j], j + 1 - sequence_begin));
                sequence_begin = j + 1;
            }
        }
    }

    return compressed_bitmap;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(
    const std::vector<std::pair<uint8_t, uint8_t>>& compressed_bitmap) {
    std::array<std::array<uint8_t, width>, height> decompressed_bitmap;
    int i = 0, j = 0;
    for (auto element : compressed_bitmap) {
        auto value = element.first;
        auto quantity = element.second;

        do {
            decompressed_bitmap[i][j++] = value;
            quantity--;
            if (j == width) {
                i++;
                j = 0;
            }
        } while (quantity >= 1);
    }

    return decompressed_bitmap;
}

void printMap(const std::array<std::array<uint8_t, width>, height>& decompressed_bitmap) {
    for (const auto& row : decompressed_bitmap) {
        for (const auto& ch : row) {
            if (ch < min_printable) {
                std::cout << ' ';
            }
            else {
                std::cout << ch;
            }
        }
        std::cout << '\n';
    }
}
