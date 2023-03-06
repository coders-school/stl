#include <iostream>
#include<array>
#include<forward_list>
#include<string>
#include <vector>

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, 32>, 32>& image){
    std::vector<std::pair<uint8_t, uint8_t>> compressed;
    for (auto& row : image){
        uint8_t last = row[0];
        uint8_t count = 1;
        for (auto& pixel : row){
            if (pixel == last){
                count++;
            } else {
                compressed.push_back(std::make_pair(last, count));
                last = pixel;
                count = 1;
            }
        }
        compressed.push_back(std::make_pair(last, count));
    }
    return compressed;
}