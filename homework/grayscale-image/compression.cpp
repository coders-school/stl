#include "compression.hpp"
#include <algorithm>
#include <array>
#include <utility>
#include <vector>

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height> Gray) {
    std::vector<std::pair<uint8_t, uint8_t>> compress;
    for (const auto& row : Gray) {
        auto counter = 1;
        auto value = row[0];
        for (auto i = 1; i < row.size(); ++i) {
            counter++;
            if (i == (row.size() - 1)) {
                compress.push_back({value, counter});
            } else if (value != row[i]) {
                compress.push_back({value, --counter});
                value = row[i];
                counter = 1;
            }
        }
    }
    return compress;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>> Decompres) {
    std::array<std::array<uint8_t, width>, height> decompressArray;
    auto it = begin(*begin(decompressArray));
    std::for_each(Decompres.begin(), Decompres.end(), [&](auto pair) { it = std::fill_n(it, pair.second, pair.first); });
    return decompressArray;
}