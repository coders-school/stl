#include "compression.hpp"

#include <iostream>

void printMap(const std::array<std::array<uint8_t, width>, height>& bitmap) {

    for (const auto& arr : bitmap) {
        for (auto& el : arr) {
            if (el <= ASCIIno32)
                std::cout << " ";
            else
                std::cout << el;
        }
        std::cout << "\n";
    }
}

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, width>, height>& grayScale) {
    std::vector<std::pair<uint8_t, uint8_t>> compressed;
    compressed.reserve(width * height);
    int count = 0;
    int tmp = 0;

    for(const auto& row : grayScale){
        auto _prev = row.at(0);
        for(const auto& column : row){
            if(_prev == column) {
                count++;
                _prev = column;
                continue;
            }
            compressed.push_back(std::make_pair(_prev, count));
            _prev = column;
            count = 1;
        }
        compressed.push_back(std::make_pair(_prev, count));
        count = 0;
    }

    compressed.shrink_to_fit();

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
        if(i == width){
            decompressed[j++] = tmpArray;
            i = 0;
        }
    }

    return decompressed;
}
