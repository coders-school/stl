#include "decompressGrayscale.hpp"

std::array<std::array<uint8_t, width>, height> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>>& v) {
    std::array<std::array<uint8_t, width>, height> arr;
    int row = 0, col = 0;
    for (const auto& [color, count] : v) {
        for (int i = 0; i < count; i++) {
            arr[row][col++] = color;
            if (col == 240) {
                col = 0;
                row++;
            }
        }
    }
    return arr;
}