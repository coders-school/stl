#pragma once
#include <array>
#include <vector>
#include "compression.hpp"

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, width>, height>& arrImage) {
    std::vector<std::pair<uint8_t, uint8_t>> vecTemp;
    std::pair<uint8_t, uint8_t> pairTemp;
    vecTemp.reserve(height*width);
    for (const auto & el_height : arrImage) {
        pairTemp.first = el_height.front();
        for (const auto & el_width : el_height) {
            if (el_width == pairTemp.first) {
                ++pairTemp.second;
            }
            else {
                vecTemp.push_back(pairTemp);
                pairTemp.first = el_width;
                pairTemp.second = 1;
            }
        }
        vecTemp.push_back(pairTemp);
        pairTemp.second = 0;
    }
    vecTemp.shrink_to_fit();
    return vecTemp;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(const std::vector<std::pair<uint8_t, uint8_t>>& vecCompressed) {
    std::array<std::array<uint8_t, width>, height> arrTemp;
    int row = 0;
    int column = 0;

    while (row <= height){
        while(column <= width) {
            column = 0;
            for(const auto & el : vecCompressed){
                for(int i = 0; i < el.second; ++i) {
                    arrTemp[row][column + i] = el.first;
                }
                column += el.second;
            }
        }
        ++row;
    }
    return arrTemp;
}