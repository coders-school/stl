#include "compression.hpp"

std::vector<int> vectorCopy(std::vector<int> input){
    return input;
}

std::vector<std::pair<uint8_t,uint8_t>>  compressGrayscale(std::array<std::array<uint8_t,width>,height> bitmap) {
    std::vector<std::pair<uint8_t,uint8_t>> compressed;
    compressed.reserve(width * height);
    for (const auto& line : bitmap) {
        uint8_t counter = 1;
        for (auto it = line.begin(); it != line.end(); it++) {
            if (*it != *std::next(it) || it == line.end() - 1) {
                compressed.push_back(std::make_pair(*it, counter));
                counter = 1;
            } else {
                counter++;
            }
        }
    }
    return compressed;
}

std::array<std::array<uint8_t,width>,height>  decompressGrayscale(std::vector<std::pair<uint8_t,uint8_t>> compressed) {
    std::array<std::array<uint8_t,width>,height> decompressed;
    /*
    Transforms vector of pairs(char value,char count) into a 2D-array of char
    */
    size_t rowCounter = 0;
    size_t columnCounter = 0;

    for (const auto& pair : compressed) {
        if (rowCounter < height) {
            for (size_t consecutiveValues = 0; consecutiveValues < pair.second; ++consecutiveValues) {
                decompressed[rowCounter][columnCounter] = pair.first;
                if (columnCounter < width - 1) {
                    columnCounter++;
                } else {
                    columnCounter = 0;
                    rowCounter++;
                }
            }
        }
    }
    
    return decompressed;
}