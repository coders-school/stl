#include <iostream>

#include "grayscale.hpp"


std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height>){
    //TO DO
}

void printMap (const std::array<std::array<uint8_t, width>, height>& inputMap){
    for(const auto& mapRow : inputMap){
        for(const auto& rowElement : mapRow){
            std::cout << rowElement;
        }
        std::cout << '\n';
    }
}
