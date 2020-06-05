#include "compression.hpp"

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height>) {
    return {std::make_pair<uint8_t, uint8_t>(0, 0)};
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(const std::vector<std::pair<uint8_t, uint8_t>>& compressedMap) {
    std::array<std::array<uint8_t, width>, height> decompressed;

    unsigned int row = 0;
    unsigned int col = 0;

    for (const auto& [color, count] : compressedMap) {
        for (unsigned int i = 0; i < count; i++) {
            decompressed[row][col] = color;
            if (col < width - 1) {
                col++;
            } else {
                col = 0;
                row++;
            }
        }
    }

    return decompressed;
}
