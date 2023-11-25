#include <algorithm>
#include "compression.hpp"

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height> input) {
    std::vector<std::pair<uint8_t, uint8_t>> vec;

    std::for_each(input.begin(), input.end(), [&vec](auto tab) mutable {
        auto position = tab.begin();
        int count = 0;
        int val = 0;
        for (; position != tab.end();) {
            val = *position;
            auto upper = std::find_if(position, tab.end(), [i{*position}](auto a) { return a != i; });
            count = std::distance(position, upper);
            // std::fill_n(std::back_inserter(vec), 1, std::pair<uint8_t, uint8_t>{val, count});
            vec.push_back(std::pair<uint8_t, uint8_t>{val, count});
            count = 0;
            position = upper;
        }
    });
    return vec;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>>& compress) {
    std::array<std::array<uint8_t, width>, height> res;

    size_t i = 0;
    size_t j = 0;

    for (const auto &e: compress) {
        size_t count = std::min<size_t>(e.second, 32 - j);

        std::fill_n(res[i].begin() + j, count, e.first);

        j += count;

        if (j >= 32) {
            i++;
            j = 0;
        }
    }

    return res;
}
