#include "compression.hpp"

#include <iostream>
#include <algorithm>

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height> getGrey) {

std::vector<std::pair<uint8_t, uint8_t>> smallMap;

for (auto everyRow : getGrey) {

    std::array<uint8_t, width>::iterator firstIt = everyRow.begin();

    while (firstIt != everyRow.end()) {

        auto secondIt = std::find_if_not(firstIt,everyRow.end(), [firstIt](int x){return x == *firstIt;});
        auto dist = std::distance(firstIt, secondIt);
        smallMap.emplace_back(std::make_pair(*firstIt,dist));
        firstIt = secondIt;
    }
}

return smallMap;

}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>> resGrey) {


return {};

}

void printMap (const std::array<std::array<uint8_t, width>, height>& getMap){

    for(const auto& everyRow : getMap){

        for(const auto& element : everyRow){
            std::cout << (uint16_t)element;
        }
        std::cout << "\n";
    }
}
