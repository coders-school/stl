#include "compression.hpp"

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, height>, width> bMap) {
    std::vector<std::pair<uint8_t, uint8_t>> xbMap;
    uint8_t last_color = bMap[0][0];
    uint8_t count = 1;
    int temp = 0;

    for (int row = 0; row < width; row++) {
        for (int col = 0; col < height; col++) {
            if (bMap[row][col] == last_color && temp == 0) {
                count++;
            } else {
                xbMap.push_back(std::make_pair(last_color, count));
                last_color = bMap[row][col];
                count = 1;
                temp = 0;
            }
        }
        temp = 1;
    }
    xbMap.push_back(std::make_pair(last_color, count));
    return xbMap;
}