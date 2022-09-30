#include "compression.hpp"

[[deprecated("No longer needed")]] void pasteToVector(std::vector<std::pair<uint8_t, uint8_t>>& vector, int count, int number) {
    vector.emplace_back(number, count);
}

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, width>, height>& arr) {
    std::vector<std::pair<uint8_t, uint8_t>> vector;
    vector.reserve(width * height);
    for (int i = 0; i < height; ++i) {
        int count = 1;
        for (int j = 1; j < width; ++j) {
            if (arr[i][j] != arr[i][j - 1]) {
                vector.emplace_back(arr[i][j - 1], count);
                count = 0;
            }
            ++count;
        }
        vector.emplace_back(arr[i][width - 1], count);
    }
    vector.shrink_to_fit();
    return vector;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(const std::vector<std::pair<uint8_t, uint8_t>>& bitmap) {
    return std::array<std::array<uint8_t, width>, height>();
}
