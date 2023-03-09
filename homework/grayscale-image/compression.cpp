#include "compression.hpp"



std::vector<std::pair<uint8_t, uint8_t>>
 compressGrayscale(const std::array<std::array<uint8_t, width>, height>& image){
    std::vector<std::pair<uint8_t, uint8_t>> compressed;
    for (auto i = 0; i < height; i++) {
        uint8_t last = 0;
        uint8_t count = 1;
        for (auto j = 0; j < width; j++) {
            if (j == 0) {
                last = image[i][j];
            } else {
            if (last == image[i][j]){
                count++;
            } else {
                compressed.push_back(std::make_pair(last, count));
                last = image[i][j];
                count = 1;
            }
            }
        }
        compressed.push_back(std::make_pair(last, count));
    }
    return compressed;
}


std::array<std::array<uint8_t, width>, height>
 decompressGrayscale(const std::vector<std::pair<uint8_t, uint8_t>>& compressed){
    std::array<std::array<uint8_t, width>, height> decompressed;
    int row = 0;
    int col = 0;
    for(auto& pair : compressed){
        for (int i = 0; i < pair.second; i++){
            decompressed[row][col] = pair.first;
            col++;
            if (col == width){
                col = 0;
                row++;
            }

        }

    }
    return decompressed;
}