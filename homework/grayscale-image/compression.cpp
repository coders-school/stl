#include "compression.hpp"
#include <iostream>
#include <algorithm>

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, 32>, 32> bitmap_array){
    std::vector<std::pair<uint8_t, uint8_t>> compresed_vector;
    int rows = sizeof(bitmap_array)/sizeof(bitmap_array[0]);
    int cols = sizeof(bitmap_array[0])/sizeof(bitmap_array[0][0]);
    
    for (int i = 0; i < cols; i++){
        for (int j = 0; j < rows; j++){
            if (compresed_vector.size() != 0 && j != 0 && compresed_vector.back().first == bitmap_array[i][j]){
                compresed_vector.back().second ++;
            }
            else {
                compresed_vector.emplace_back(bitmap_array[i][j], 1);
            }
        }
    }
    std::vector<int>vec(rows * cols);
    // std::transform(begin(vec), end(vec), begin(vec), [](auto str) {
    //     std::transform(begin(str), end(str), begin(str), [](auto c) {
    //     return std::tolower(c);
    //     });
    // return str;
    // });
    std::transform(&bitmap_array[1][1], &bitmap_array[1][2], vec.begin(), 
            [](auto some) {
                    
            return some;
            });
    // for (auto a: vec){
    //     std::cout << a << "\n";
    // }
    return compresed_vector;
}