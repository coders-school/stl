#include "compression.hpp"

#include <algorithm>
#include <iostream>


char convert2Printable(uint8_t input) {
    return ::isgraph(input) ?  input : ' ';
}

void printMap(const RawMap& input) {   
    for(const auto& row : input) {
        for(const auto & cell : row) {
           std::cout << convert2Printable(cell);
        }
        std::cout << '\n';
        }
}

void printVectorOfPairs(const Compressed& input) {
    int elementCounter = 0;
    for(const auto& element : input) {
        elementCounter ++;
        std::cout << "{" << +element.first << ", " << +element.second << "}" << ' ';
        if(elementCounter % 32 == 0) {
            std::cout << "\n";
            
        }
    }
    std::cout << '\n';
}

Compressed compressGrayscale(const RawMap& input) {
    Compressed returnValue{};
    returnValue.reserve(height * width);
    for(const auto& row : input) {
        auto current = row.begin();
        while(current != row.end()) {
            uint8_t value = *current;
            auto index = std::find_if(current, row.end(), 
                                      [value](uint8_t nextValue) {
                                        return value != nextValue;
                                      });
            uint8_t counter = static_cast<uint8_t>(std::distance(current, index));
            returnValue.emplace_back(value, counter);
            current = index;
        }
    }
    returnValue.shrink_to_fit();
    return returnValue;
}

RawMap decompressGrayscale(const Compressed& inVec) {
    RawMap returnValue{};
    uint8_t column{0}, row{0};
    
    for(const auto& element : inVec) {
        for(uint8_t i = column; i < column + element.second; ++i) {
            returnValue[row][i] = element.first;
        }
        column += element.second;
        if(column == width) {
            column = 0;
            ++row;
        }
    }
        return returnValue;
}
