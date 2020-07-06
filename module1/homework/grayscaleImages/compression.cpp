#include "compression.hpp"

#include <iostream>

void printMap(const std::array<std::array<uint8_t, height>, width>& input) {   
    for(size_t i = 0; i < height; ++i) {
        for(size_t j = 0; j < width; j++) {
            std::cout << input[i][j] << ' ';
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

void printVectorOfPairs(const std::vector<std::pair<uint8_t, uint8_t>>& input) {
    for(const auto& element : input) {
        std::cout << "{" << +element.first << ", " << +element.second << "}" << ' ';
    }
    std::cout << '\n';
}

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, height>, width>& input) {
    std::vector<std::pair<uint8_t, uint8_t>> returnValue{};
    size_t maximumVectorSize = height * width;
    returnValue.reserve(maximumVectorSize);
    bool breakInnerLoop{};
    size_t count{}, j{}, k{};
    
    for(size_t i = 0; i < height; ++i) {
        breakInnerLoop = false;
        j = k = 0;
        while(!breakInnerLoop) {
            if(input[i][j] == input[i][k]) {
                ++count;
                ++k;
            } else {
                returnValue.emplace_back(std::make_pair(input[i][j], static_cast<uint8_t>(count)));
                count = 0;
                j = k;
            }
            if (k == width) {
                returnValue.emplace_back(std::make_pair(input[i][j], static_cast<uint8_t>(count)));
                count = 0;
                breakInnerLoop = true;
            }
        }
    }   
    returnValue.shrink_to_fit();
    return returnValue;
}

std::array<std::array<uint8_t, height>, width> decompressGrayscale(const std::vector<std::pair<uint8_t, uint8_t>>& inVec) {
    std::array<std::array<uint8_t, height>, width> retArr{};
    size_t a1{}, a2{}, c{}, v{};
    while(a1 < height) {
        a2 = 0;
        while(a2 < width) {
            c = 0;
            while(c < static_cast<size_t>(inVec[v].second)) {
                retArr[a1][a2] = inVec[v].first;
                ++a2;
                ++c;
            }
            ++v;
        }
        ++a1;
    }
    return retArr;
}
