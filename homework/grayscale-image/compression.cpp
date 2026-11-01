#include "compression.hpp"

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, width>, height>& bitmap) {
    std::vector<std::pair<uint8_t, uint8_t>> compresed;
    compresed.reserve(width * height);

    for (const auto& row : bitmap) {
        uint8_t repetition = 1;
        uint8_t bit = row.front();

        for (auto it = row.begin() + 1; it != row.end(); ++it) {
            auto elem = *it;

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
    return {};
}
