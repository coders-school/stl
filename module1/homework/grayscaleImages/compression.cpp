#include "compression.hpp"

#include <iostream>

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height> getGrey) {

std::vector<std::pair<uint8_t, uint8_t>> smallMap;
//smallMap.reserve(width);



return {};

}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>> resGrey) {


return {};

}

void printMap (const std::array<std::array<uint8_t, width>, height>& getMap){

    for(const auto& everyRow : getMap){
        for(const auto& element : everyRow){
            std::cout << element;
        }
        std::cout << "\n";
    }
}
