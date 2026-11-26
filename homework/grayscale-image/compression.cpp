#include "compression.hpp"
#include <algorithm>
#include <array>
#include <utility>
#include <vector>

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(
    const std::array<std::array<uint8_t, width>, height>& image) {
    std::vector<std::pair<uint8_t, uint8_t>> compressed;

    std::for_each(image.begin(), image.end(), [&](const auto& row) {
        uint8_t currentColor = row[0];
        uint8_t count = 0;

        std::for_each(row.begin(), row.end(), [&](uint8_t pixel) {
            if (pixel == currentColor && count < 255) {
                ++count;
            } else {
                compressed.push_back({currentColor, count});
                currentColor = pixel;
                count = 1;
            }
        });

        compressed.push_back({currentColor, count});
    });

    return compressed;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(
    const std::vector<std::pair<uint8_t, uint8_t>>& compressed) {
    std::array<std::array<uint8_t, width>, height> image{};

    size_t position = 0;

    std::for_each(compressed.begin(), compressed.end(), [&](const auto& pair) {
        auto [color, count] = pair;

        size_t rowIndex = position / width;
        size_t columnIndex = position % width;

        std::fill_n(
            image[rowIndex].begin() + columnIndex,
            count,
            color);

        position += count;
    });

    return image;
}
