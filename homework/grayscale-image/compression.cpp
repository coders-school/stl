#include "compression.hpp"

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, width>, height> &bMap) {
    std::vector<std::pair<uint8_t, uint8_t>> xbMap;
    uint8_t last_color = bMap[0][0];
    uint8_t count = 0;
    int temp = 0;

    for (size_t row = 0; row < width; row++) {
        for (size_t col = 0; col < height; col++) {
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

/*
std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height> &arr) {
    std::vector<std::pair<uint8_t, uint8_t>> compression{std::make_pair(arr[0][0], 0)};
    int iv = 0;
    for(std::size_t i = 0; i < height; i++) {
        for(std::size_t j = 0; j < width; j++) {
            if (compression[iv].first == arr[i][j]) {
                compression[iv].second +=1;
            } else {
              compression.push_back(std::make_pair(arr[i][j], 1));
              ++iv;
            }
            if (j == width - 1 && i != height - 1) {
              compression.push_back(std::make_pair(arr[i+1][0], 0));
              iv++;
            }
        }
    }
    return compression;
    
}*/

std::array<std::array<uint8_t, width>, height> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>> &vec) {
    std::array<std::array<uint8_t, width>, height> decompression;
    std::size_t k = 0;
      for(std::size_t i = 0; i < height; i++) {
        for(std::size_t j = 0; j < width; ) {
          std::size_t count = 0;
          while(count < vec[k].second) {
            decompression[i][j] = vec[k].first;
            j++;
            count++;
          }
          k++;
        }
    }
    return decompression;
}