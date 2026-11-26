#include "compression.hpp"
#include <array>
#include <utility>
#include <vector>

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(
    const std::array<std::array<uint8_t, width>, height>& image) {
    std::vector<std::pair<uint8_t, uint8_t>> compressed;

    for (size_t i = 0; i < height; ++i) {
        uint8_t currentColor = image[i][0];
        uint8_t count = 0;

        for (size_t j = 0; j < width; ++j) {
            if (image[i][j] == currentColor && count < 255) {
                ++count;
            } else {
                compressed.push_back({currentColor, count});
                currentColor = image[i][j];
                count = 1;
            }
        }

        compressed.push_back({currentColor, count});
    }

    return compressed;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(
    const std::vector<std::pair<uint8_t, uint8_t>>& compressed) {
    std::array<std::array<uint8_t, width>, height> image{};

    size_t position = 0;

    for (const auto& [color, count] : compressed) {
        for (uint8_t i = 0; i < count; ++i) {
            image[position / width][position % width] = color;
            ++position;
        }
    }

    return image;
}