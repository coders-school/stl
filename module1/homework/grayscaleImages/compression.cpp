#include "compression.hpp"

#include <algorithm>
#include <array>
#include <cstdint>
#include <vector>

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height>& a) {
    std::vector<std::pair<uint8_t, uint8_t>> v;

    for (size_t i = 0; i < height; ++i) {
        uint8_t current = a[i][0];
        size_t count = 0;

        for (size_t j = 0; j < width; ++j) {
            if (a[i][j] == current) {
                ++count;
            }
            else {
                v.push_back(std::make_pair(current, count));
                current = a[i][j];
                count = 1;
            }
            if (j == 31)
                v.push_back(std::make_pair(current, count));
        }
    }

    return v;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>>& v) {
    std::array<std::array<uint8_t, width>, height> a;

    std::vector<uint8_t> temp;
    temp.reserve(width * height);

    for (const auto &i : v)
        temp.insert(end(temp), i.second, i.first);

    int cur = 0;
    for (auto &row : a) {
        for (auto &col : row) {
            col = temp[cur++];
        }
    }

    return a;
}
