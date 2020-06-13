#include "compression.hpp"

#include <cstdint>

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, width>, height>& bitmap) {
   
    uint8_t counter = 1;
    std::vector<std::pair<uint8_t, uint8_t>> compressed_bitmap;
    for (size_t row = 0; row < height; ++row) {
        for (size_t col = 0; col < width - 1; ++col) {
            if (col == width - 2) {
                if(bitmap[row][col] == bitmap[row][col + 1]) {
                compressed_bitmap.push_back(std::pair<uint8_t, uint8_t>(bitmap[row][col], counter + 1));
                counter = 1;
                } else {
                    compressed_bitmap.push_back(std::pair<uint8_t, uint8_t>(bitmap[row][col], counter));
                    counter = 1;
                    compressed_bitmap.push_back(std::pair<uint8_t, uint8_t>(bitmap[row][col + 1], counter));
                }
                continue; 
            }
            if(bitmap[row][col] == bitmap[row][col + 1]) {
                counter++;
            } else {
                compressed_bitmap.push_back(std::pair<uint8_t, uint8_t>(bitmap[row][col], counter));
                counter = 1;
            }
        }
    }
    return compressed_bitmap;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>>&) {};
