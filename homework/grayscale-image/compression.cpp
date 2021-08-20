#pragma once
#include <array>
#include <vector>
#include "compression.hpp"

void Show_arr(std::array<std::array<uint8_t, width>, height>  a_t_t);

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, width>, height>& a_T) {
    std::vector<std::pair<uint8_t, uint8_t>> v_t;
    std::pair<uint8_t, uint8_t> p_t;
    for (const auto & el_height : a_T) {
        p_t.first = el_height.front();
        for (const auto & el_width : el_height) {
            if (el_width == p_t.first) {
                ++p_t.second;
            }
            else {
                v_t.push_back(p_t);
                p_t.first = el_width;
                p_t.second = 1;
            }
        }
        v_t.push_back(p_t);
        p_t.second = 0;
    }
    v_t.shrink_to_fit();
    return v_t;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(const std::vector<std::pair<uint8_t, uint8_t>>& v_2) {
    std::array<std::array<uint8_t, width>, height> arrTemp;
    int row = 0;
    int column = 0;

    while (row <= height){
        while(column <= width) {
            column = 0;
            for(const auto & el : v_2){
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