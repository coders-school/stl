#include "compression.hpp"

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, width>, height>& arr) {
    std::vector<std::pair<uint8_t, uint8_t>> vec;

    return vec;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(const std::vector<std::pair<uint8_t, uint8_t>>& vec) {
    std::array<std::array<uint8_t, width>, height> arr;

    auto x = 0;
    auto y = 0;

    for (auto el : vec) {
        std::fill(&arr[x][y], &arr[x][y + el.second], el.first);
        y += el.second;
        if (y >= width) {
            x++;
            y = 0;
        }
    }

    return arr;
}

void printMap(const std::array<std::array<uint8_t, width>, height>& arr) {
}
