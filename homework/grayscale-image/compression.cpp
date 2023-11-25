#include <algorithm>
#include "compression.hpp"

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, 32>, 32> &img) {
    std::vector<std::pair<uint8_t, uint8_t>> res;

    for (size_t i = 0; i < img.size(); ++i) {
        auto &row = img[i];

        auto begin = row.begin();
        auto end = row.end();

        while (begin != end) {
            auto next = std::adjacent_find(begin, end, std::not_equal_to<uint8_t>());

            uint8_t value = *begin;
            uint8_t count = std::distance(begin, next);

            res.emplace_back(value, count + 1);

            if (next == end) {
                break;
            }

            begin = next + 1;
        }
    }

    return res;
}

std::array<std::array<uint8_t, 32>, 32> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>> &compress) {
    std::array<std::array<uint8_t, 32>, 32> res;

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
