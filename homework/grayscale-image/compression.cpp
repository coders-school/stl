#include "compression.hpp"

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height> image){
    std::vector<std::pair<uint8_t, uint8_t>> vec_pair;
    for(size_t i=0; i<height; ++i){
        uint8_t counter = 1;
        uint8_t  color = 0;
        for(size_t j=1; j<=width; ++j){
            if(j == width || image.at(i).at(j-1) != image.at(i).at(j) ){
                if(counter == 1){
                    color = image.at(i).at(j-1);
                    vec_pair.push_back(std::make_pair(color,counter));
                }else{
                    color = image.at(i).at(j-1);
                    vec_pair.push_back(std::make_pair(color,counter));
                    counter = 1;
                }
            }else{
                ++counter;
            }
            
        }
    }
    return vec_pair;
};

std::array<std::array<uint8_t, width>, height> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>> vec) {
    std::array<std::array<uint8_t, width>, height> array_out;
    uint8_t x = 0;
    uint8_t y = 0;
    for (auto& pair : vec) {
        uint8_t color = pair.first;
        uint8_t count = pair.second;
        for (size_t i = 0; i < count; ++i) {
            if (x < width) {
                array_out[y][x] = color;
                ++x;
                if (x == width) {
                    ++y;
                    x = 0;
                }
            }
        }
    }
    return array_out;
}

void printMap(const std::array<std::array<uint8_t, width>, height>& ninja) {
    for (const auto& elem : ninja) {
        for (const auto& el : elem) {
            if (el < ' ') {
                std::cout << ' ';
            } else {
                std::cout << el;
            }
        }
        std::cout << '\n';
    }
}