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
    size_t rowCounter = 0;
    size_t columnCounter = 0;

    for(const auto& pair : inputVec){
        if (rowCounter < height){
            for(size_t pairValue = 0; pairValue<pair.second; ++pairValue){
                outputArr[rowCounter][columnCounter] = pair.first;
                if(columnCounter < width-1)
                    columnCounter++;
                else{
                    columnCounter = 0;
                    rowCounter++;
                } 
            }
        } 
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
