#include "compression.hpp"
#include <iostream>

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, width>, height>& image_array) {
    std::vector<std::pair<uint8_t, uint8_t>> compressed;
    compressed.reserve(width * height);
    for (auto row : image_array) {
        int number_of_color = 0;
        uint8_t previous_color = 0;
        for (auto it = row.begin(); it != row.end(); it++) {
            if (!number_of_color) {
                previous_color = *it;
            }
            if (previous_color == *it) {
                number_of_color++;
            } else {
                compressed.push_back(std::make_pair(previous_color, number_of_color));
                number_of_color = 1;
                previous_color = *it;
            }
            if (it == row.end() - 1) {
                compressed.push_back(std::make_pair(previous_color, number_of_color));
            }
       }
    }
    compressed.shrink_to_fit();
    return compressed;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(const std::vector<std::pair<uint8_t, uint8_t>>& image_vector) {
    std::array<std::array<uint8_t, width>, height> decompressed;
    int position = 0;
    int row = 0;
    for (auto el : image_vector) {
        for (int i = 0; i < el.second; i++) {
            decompressed[row][i + position] = el.first;
        }
        position += el.second;
        if (position == width) {
            row++;
            position = 0;
        }
    }
    return decompressed;
}

