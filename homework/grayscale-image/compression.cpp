#include "compression.hpp"

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, 32>, 32>& img){
    std::vector<std::pair<uint8_t, uint8_t>> res;

    for (size_t i{0}; i < height; ++i) {
        uint8_t curr{img.at(0).at(0)};
        uint8_t t{1};
        for (size_t j{0}; j < width-1; ++j) {
            if (curr == img.at(i).at(j+1)) {
                t++;
                continue;
            }
            res.emplace_back(curr, t);
            curr = img.at(i).at(j+1);
            t = 1;
        }
        res.emplace_back(curr, t);
    }

    return res;
}

std::array<std::array<uint8_t, 32>, 32> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>>& compress) {
    std::array<std::array<uint8_t, 32>, 32> res;

    size_t i{0};
    size_t j{0};
    for (const auto& e : compress) {
        for (uint8_t k{0}; k < e.second; ++k) {
            if (j >= width)
                break;
            res.at(i).at(j++) = e.first;
        }
        if (j >= width) {
            i++;
           j = 0;
        }
    }

  return res;
}
