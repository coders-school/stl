#include "compression.hpp"
#include <iostream>

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height> input) {
    std::vector<std::pair<uint8_t, uint8_t>> pp;

    // szeros only
    int cnt = 0;
    auto current_value = input[0][0];
    bool the_same_value = true;
    for (size_t h = 0; h < height; ++h) {
        for (size_t w = 0; w < width; ++w) {
            uint8_t new_value = input[h][w];
            std::cout << w << ", " << h << " value = " << unsigned(new_value) << std::endl;
            if (new_value == current_value) {
                ++cnt;
            } else {
                the_same_value = false;
                std::cout << "wchodze" << std::endl;
                pp.push_back(std::pair{current_value, cnt});
                cnt = 0;
            }
        }
    }

    std::cout << "the_same_value " << the_same_value << std::endl;
    std::cout << "cnt " << cnt << std::endl;
    if (the_same_value) {
        for (size_t h = 0; h < height; ++h)
        {
            pp.push_back(std::pair{current_value, cnt / height});
        }
        return pp;
    }

    std::cout << "size = " << cnt << std::endl;
    return pp;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>> input) {
    std::array<std::array<uint8_t, width>, height> output{};
    return output;
}