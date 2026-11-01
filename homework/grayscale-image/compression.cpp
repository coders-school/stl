#include "compression.hpp"

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, width>, height>& bitmap) {
    std::vector<std::pair<uint8_t, uint8_t>> compresed;
    compresed.reserve(width * height);

    for (const auto& row : bitmap) {
        uint8_t repetition = 1;
        uint8_t bit = row.front();

        for (auto it = row.begin() + 1; it != row.end(); ++it) {
            const uint8_t elem = *it;

            if (bit == elem) {
                repetition++;
            } else {
                compresed.emplace_back(bit, repetition);

                bit = elem;
                repetition = 1;
            }
        }

        compresed.emplace_back(bit, repetition);
    }

    compresed.shrink_to_fit();

    return compresed;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(const std::vector<std::pair<uint8_t, uint8_t>> compressed) {
    std::array<std::array<uint8_t, width>, height> bitmap;

    std::size_t row = 0;
    std::size_t col = 0;

    for (const auto& pair : compressed) {
        uint8_t bit = pair.first;
        uint8_t rep = pair.second;

        while (rep) {
            bitmap[row][col] = bit;
            --rep;

            col++;

            if (col == width) {
                col = 0;
                row++;
            }

            if (row == height) {
                return bitmap;
            }
        }
    }

    return bitmap;
}
