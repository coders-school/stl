#include <array>
#include <utility>
#include <vector>

#include "compression.hpp"

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height> picture) {
    std::vector<std::pair<uint8_t, uint8_t>> compressedPicutre;

    for (const auto& row : picture) {
        auto it = row.begin();
        auto count = 1;
        for (const auto& el : row) {
            auto number = *it;
            if (++it != row.end() && *it == number) {
                ++count;
            } else {
                compressedPicutre.emplace_back(number, count);
                count = 1;
            }
        }
    }
    return compressedPicutre;
}