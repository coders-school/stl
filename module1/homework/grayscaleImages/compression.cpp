#include "compression.hpp"

#include <algorithm>
#include <iostream>

Compressed compressGrayscale(const Image& compress) {
    Compressed compressedBitmap;

    uint8_t repetitionCounter = 0;

    for(const auto row : compress){
        repetitionCounter = 1;
        for(auto color = row.begin(); color != row.end(); ++color){
            auto nextColor = std::next(color);
            if(*color != *nextColor || nextColor == row.end()){
                compressedBitmap.emplace_back(*color,repetitionCounter);
                repetitionCounter = 1;
            }
            else{
                repetitionCounter++;
            }
        }
    }
    compressedBitmap.shrink_to_fit();
    return compressedBitmap;
}

Image decompressGrayscale(const Compressed& compressedMap) {
    Image decompressed;

    size_t row = 0;
    size_t col = 0;

    for (const auto& [color, count] : compressedMap) {
        if (row < height) {
            for (size_t i = 0; i < count; i++) {
                decompressed[row][col] = color;
                if (col < width - 1) {
                    col++;
                } else {
                    col = 0;
                    row++;
                }
            }
        } else {
            break;
        }
    }

    return decompressed;
}

void printMap(const std::array<std::array<uint8_t, width>, height>& mapToPrint) {
    for (const auto& row : mapToPrint) {
        for (const auto& el : row) {
            std::cout << el;
        }
        std::cout << '\n';
    }
}
