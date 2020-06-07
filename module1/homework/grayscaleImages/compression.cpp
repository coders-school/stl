#include "compression.hpp"

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