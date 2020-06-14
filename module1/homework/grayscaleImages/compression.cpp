#include "compression.hpp"

#include <iostream>

void printMap(const std::array<std::array<uint8_t, width>, height>& bitmap) {
    for (auto arr : bitmap) {
        for (auto el : arr) {
            if (iscntrl(el))
                std::cout << " ";
            else
                std::cout << el;
        }
        std::cout << "\n";
    }
}

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, width>, height>& grayScale) {
    std::vector<std::pair<uint8_t, uint8_t>> compressed;
    compressed.reserve(width * height);
    uint8_t count = 0;

    for (auto row : grayScale) {
        auto _prev = row.front();
        for (auto column : row) {
            if (_prev == column) {
                count++;
                _prev = column;
                continue;
            }
            compressed.push_back({_prev, count});
            _prev = column;
            count = 1;
        }
        compressed.push_back({_prev, count});
        count = 0;
    }

    compressed.shrink_to_fit();

    return compressed;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(const std::vector<std::pair<uint8_t, uint8_t>>& compressed) {
    std::array<std::array<uint8_t, width>, height> decompressed;
    int i = 0;
    int j = 0;

    for (const auto& pair : compressed) {
        for (int count = 0; count < pair.second; count++, j++)
            decompressed[i].at(j) = pair.first;
        if (j == width) {
            i++;
            j = 0;
        }
    }

    return decompressed;
}
