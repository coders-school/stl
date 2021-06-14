#include "compression.hpp"
#include <vector>
#include <array>
#include <utility>
#include <iostream>

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<std::uint8_t, width>, height>& arr){
    std::vector<std::pair<uint8_t, uint8_t>> vec{};
    int counter {1};
    for(size_t i=0; i<width; ++i){
        for(size_t j=0; j<height; ++j){
            if(j<height-1 && arr[i].at(j)==arr[i].at(j+1)){
                ++counter;
            }
            else if(j==height-1){
                std::pair<uint8_t, uint8_t> p = std::make_pair(arr[i].at(j),counter);
                vec.push_back(p);
                counter = 1;
            }
            else{
                std::pair<uint8_t, uint8_t> p = std::make_pair(arr[i].at(j),counter);
                vec.push_back(p);
                counter = 1;
            }
        }
    }

    return vec;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(const std::vector<std::pair<uint8_t, uint8_t>>& vec){
    std::array<std::array<uint8_t, width>, height> arr;
    uint8_t value {};
    uint8_t counter {};
    int i{};
    int j{};
    for(auto it=vec.begin(); it!=vec.end(); ++it){
        value = (*it).first;
        counter = (*it).second;
        for(int k=0; k<(int)counter; ++k){
            arr[i].at(j) = value;
            ++j;
        }
        if(j==height){
            ++i;
            j=0;
        }
    }

    return arr;
}

void printMap(const std::array<std::array<std::uint8_t, width>, height>& arr){
    for(size_t i=0; i<width; ++i){
        for(size_t j=0; j<height; ++j){
            std::cout << (int)arr[i].at(j);
        }
        std::cout << '\n';
    }
}

