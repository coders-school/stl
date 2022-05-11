#include "compression.hpp"
#include <iostream>

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height>& arr) {
    std::vector<std::pair<uint8_t, uint8_t>> vec{};
    size_t counter{1};

    for (size_t i = 0; i < height; ++i) {
        for (size_t j = 0, k = j + 1; j < width, k < width; j++, k++) {
            if (arr[i][j] == arr[i][k]) {
                counter++;
            } else {
                vec.push_back(std::make_pair(arr[i][j], static_cast<uint8_t>(counter)));
                counter = 1;
            }

            if (k == (width - 1)) {
                vec.push_back(std::make_pair(arr[i][j], static_cast<uint8_t>(counter)));
            }
        }
        counter = 1;
    }
    return vec;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>>) {
    std::array<std::array<uint8_t, width>, height> arr{};
    return arr;
}
