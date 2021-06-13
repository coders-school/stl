#include "compression.hpp"

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height>& array) {
    std::vector<std::pair<uint8_t, uint8_t>> ret;
    ret.reserve(width * height);

    for (auto& row : array) {
        for (auto it = std::next(row.begin()); it != row.end(); ++it) {
            auto& value = *it;
            static unsigned int samePrevValueCount = 1;

            if (*std::prev(it) == value) {
                samePrevValueCount++;
            } else {
                ret.push_back({*std::prev(it), samePrevValueCount});
                samePrevValueCount = 1;
            }

            if (it == std::prev(row.end())) {
                ret.push_back({*std::prev(it), samePrevValueCount});
                samePrevValueCount = 1;
            }
        }
    }

    ret.shrink_to_fit();
    return ret;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>>& pair) {
    std::array<std::array<uint8_t, width>, height> ret;
    size_t value_idx = 0;
    size_t row = 0;

    for (const auto& it : pair) {
        for (size_t insert_count = 0; insert_count < it.second; insert_count++) {
            
            ret.at(row).at(value_idx) = it.first;
            value_idx++;

            if (value_idx == width) {
                row++;
                value_idx = 0;
            }
        }
    }

    return ret;
}