#include "compression.hpp"

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
}
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
/* void printMap(std::array<std::array<uint8_t, width>, height> &arr) {
    for(std::size_t i = 0; i < height; i++) {
        for(std::size_t j = 0; j < width; j++) {
            std::cout << arr[i][j];
        }
        std::cout << '\n';
    } 
} */