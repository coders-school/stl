#include "compression.hpp"

#include <iostream>

void printMap(const std::array<std::array<uint8_t, width>, height>& bitmap) {

    for (const auto& arr : bitmap) {
        for (const auto& el : arr) {
            if (el <= ' ')
                std::cout << " ";
            else
                std::cout << el;
        }
        std::cout << "\n";
    }
}

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, width>, height>& grayScale) {
    std::vector<std::pair<uint8_t, uint8_t>> compressed;
    compressed.reserve(width);
    int count = 1, tmp;

    for (auto row = grayScale.begin(); row != grayScale.end(); row++) {
        for (auto column = row->begin(); column != std::prev(row->end()); column++) {
            if (*(std::next(column)) != *column) {
                compressed.push_back(std::make_pair(*column, count));
                tmp = *(std::next(column));
                count = 1;
                continue;
            }
            count++;
            tmp = *column;
        }
        compressed.push_back(std::make_pair(tmp, count));
        count = 1;
    }

    return compressed;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(const std::vector<std::pair<uint8_t, uint8_t>>& compressed ){
    std::array<std::array<uint8_t, width>, height> decompressed;
    std::array<uint8_t , width> tmpArray;
    int i = 0, j = 0;

    for(const auto& pair : compressed){
            for(int count = 0; count < pair.second; count++){
                tmpArray[i++] = pair.first;
            }
            if(i == 32){
                decompressed[j++] = tmpArray;
                i = 0;
            }
    }

    return decompressed;
}
