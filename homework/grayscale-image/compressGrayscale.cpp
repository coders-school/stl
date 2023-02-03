#include "compressGrayscale.hpp"

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, width>, height>& bitmap) {
    std::vector<std::pair<uint8_t, uint8_t>> result;
    for (const auto& row : bitmap) {
        uint8_t count = 1;
        uint8_t color = row[0];
        for (int i = 1; i < row.size(); i++) {
            if (row[i] == color) {
                count++;
            } else {
                result.emplace_back(color, count);
                count = 1;
                color = row[i];
            }
        }
        result.emplace_back(color, count);
    }
    return result;
}