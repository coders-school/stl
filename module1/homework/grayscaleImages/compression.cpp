#include "compression.hpp"

#include <iostream>

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, width>, height>& bitmap) {
    std::vector<std::pair<uint8_t, uint8_t>> compress;

    int counter = 0;
    uint8_t color = 0;
    for(const auto& row : bitmap) {
        color = row[0];
        counter = 0;
        for(const auto& column : row) {
            if(column == color) {
                ++counter;
            } else {
                compress.push_back({color, counter});
                color = column;
                counter = 1;
            }
        }
        compress.push_back({color, counter});
    }

    return compress;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(const std::vector<std::pair<uint8_t, uint8_t>>& bitmap) {
    std::array<std::array<uint8_t, width>, height> decompress;

    auto it = bitmap.begin();
    int counter = 0;
    for(size_t row = 0; row < height; ++row) {
        for(size_t column = 0; column < width;) {
            while(counter++ < it->second) {
                decompress[row][column++] = it->first;
            }
            ++it;
            counter = 0;
        }
    }

    return decompress;
}

void printMap(const std::array<std::array<uint8_t, width>, height>& bitmap) {
    for(const auto& row : bitmap) {
        for(const auto& column : row) {
            if(column <= ' ') {
                std::cout << ' ';
            } else {
                std::cout << column;
            }
        }
        std::cout << '\n';
    }
    
}
