#include <array>
#include <iostream>
#include <vector>
#include "compression.hpp"

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, width>, height>& inputArray) {
    std::vector<std::pair<uint8_t, uint8_t>> vecPair{};
    uint8_t tmp = 0;
    for (int i = 0; i < height; ++i) {
        for (int j = 1; j < width; ++j) {
            ++tmp;
            if (j == (width - 1)) {
                vecPair.emplace_back(inputArray[i][j], tmp + 1);
                tmp = 0;
            } 
            else if (inputArray[i][j] != inputArray[i][j - 1]) {
                vecPair.emplace_back(inputArray[i][j-1],tmp);
                tmp = 0;
            }
        }
        tmp = 0;
    }
    return vecPair;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(const std::vector<std::pair<uint8_t, uint8_t>>& inputVecPair) {
    std::array<std::array<uint8_t, width>, height> arrImg{};
    return arrImg;
}