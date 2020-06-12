#include "compression.hpp"
#include <algorithm>
#include <iostream>

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, width>, height>& imgToCompress) {
    std::vector<std::pair<uint8_t, uint8_t>> compressedImg;
 
    for (size_t row = 0; row < height; ++row) {
        uint8_t pixCount = 0;
        for (size_t col = 0; col < width; ++col) {        
            if (col == 0 || imgToCompress[row][col] == imgToCompress[row][col-1]) {
                ++pixCount;  
            }
            else {
                compressedImg.push_back(std::make_pair(imgToCompress[row][col-1], pixCount));                
                pixCount = 1;
            }

            if (col == width - 1) {
                compressedImg.push_back(std::make_pair(imgToCompress[row][col], pixCount));
            }
        }
    }

    return compressedImg;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>> imgToDecompress) {
    std::array<std::array<uint8_t, width>, height> decompressedImg;

    auto it_imgToDecompress = imgToDecompress.begin();
    auto cnt = 0;
    std::for_each(decompressedImg.begin(), decompressedImg.end(), [&](auto& row){
        std::for_each(row.begin(), row.end(), [&](auto& el){
            el = (*it_imgToDecompress).first;
            if (++cnt == (*it_imgToDecompress).second) {
                cnt = 0;
                ++it_imgToDecompress;
            }
        });
    });

    return decompressedImg;
}

void printMap(const std::array<std::array<uint8_t, width>, height>& bitmap) {
    std::for_each(bitmap.begin(), bitmap.end(), [](const auto& row){
        std::for_each(row.begin(), row.end(), [](const auto& element){ 
            if (element < ' ') {
                std::cout << " ";
            }
            else {
                std::cout << element; 
            }
            });
        std::cout << "\n";
    });
}