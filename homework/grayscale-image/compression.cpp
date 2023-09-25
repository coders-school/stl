#include "compression.hpp"

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, width>, height>& arr){
    std::vector<std::pair<uint8_t, uint8_t>> vec;
    for(auto row : arr){
        uint8_t tmpVal = row.at(0);
        int indexPair = 1;
        for(size_t i = 1; i < row.size(); ++i){
            if(row.at(i) != tmpVal){
                vec.push_back({tmpVal, indexPair});
                tmpVal = row.at(i);
                indexPair = 1;
            }else{
                ++indexPair;
            }
        }
        vec.push_back({tmpVal, indexPair});
    }
    return vec;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(const std::vector<std::pair<uint8_t, uint8_t>>& vec){
    std::array<std::array<uint8_t, width>, height> arr;
    int indexH = 0;
    int indexW = 0;
    int vecIndex = 0;
    int valCount = vec.at(vecIndex).second;
    while(indexH < height){
        if(valCount == 0){
            ++vecIndex;
            valCount = vec.at(vecIndex).second;
        }else{
            arr[indexH][indexW] = vec.at(vecIndex).first;
            --valCount;
            ++indexW;
            if(indexW == width){
                indexW = 0;
                ++indexH;
            }
        }
    }
    return arr;
}

void printMap(const std::array<std::array<uint8_t, 32>, 32>& arr){
    for(auto row : arr){
        for(auto v : row){
            if(unsigned(v) == 0){
                std::cout << " ";
            }else if(unsigned(v) > 0 && unsigned(v) < 33){
                std::cout << " ";
            }else{
                std::cout << v;
            }
        }
        std::cout << std::endl;
    }
}