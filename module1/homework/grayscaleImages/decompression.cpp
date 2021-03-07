#include "decompression.hpp"
#include <iostream>

std::array<std::array<uint8_t, 32>, 32> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>> bitmap_compressed){
    std::array<std::array<uint8_t, 32>, 32> bitmap_arr;
    int rows = sizeof(bitmap_arr)/sizeof(bitmap_arr[0]);
    int cols = sizeof(bitmap_arr[0])/sizeof(bitmap_arr[0][0]);
    int it_bitmap = 0;
    std::pair<uint8_t, uint8_t> bitmap_arr_position;
    for (int i = 0; i < bitmap_compressed.size(); i++){
        for (int j = 0; j < bitmap_compressed[i].second; j++){
            bitmap_arr[it_bitmap / rows][it_bitmap % cols] = bitmap_compressed[i].first;
            it_bitmap++;
        }
        
    }
    return bitmap_arr;
}
