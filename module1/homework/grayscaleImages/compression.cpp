#include <algorithm>
#include <iostream>

#include "compression.hpp"


std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, width>, height>& inputMap){
    std::vector<std::pair<uint8_t, uint8_t>> outputVec {};
    uint8_t color = 0; 
    int value = 0;

    for(const auto& mapRow : inputMap){
        color = mapRow[0]; 
        value = 0;

        for(auto rowElement : mapRow){
            if(rowElement == color){
                ++value;
            }
            else{
                outputVec.emplace_back(std::make_pair(color, value));
                color = rowElement;
                value = 1;
            }    
        }
        outputVec.emplace_back(std::make_pair(color, value));
    }
    return outputVec;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(const std::vector<std::pair<uint8_t, uint8_t>>& inputVec){
    std::array<std::array<uint8_t, width>, height> outputArr;
    auto vecIt = inputVec.begin();
    size_t repeatingValue = 1;
    
    for(size_t rowCounter = 0; rowCounter < height; rowCounter++){
        repeatingValue = 1;
        for(size_t columnElement = 0; columnElement < width; columnElement++){
            if(repeatingValue <= (vecIt->second)){
                outputArr[rowCounter][columnElement] = (vecIt->first);
                repeatingValue++;
            }
            else{
                vecIt++;
                outputArr[rowCounter][columnElement] = (vecIt->first);
                repeatingValue = 2;
            }
        }
        vecIt++;
    }
    return outputArr;
}


void printMap (const std::array<std::array<uint8_t, width>, height>& inputMap){
    for(const auto& mapRow : inputMap){
        for(const auto& rowElement : mapRow){
            std::cout << rowElement;
        }
        std::cout << '\n';
    }
}
