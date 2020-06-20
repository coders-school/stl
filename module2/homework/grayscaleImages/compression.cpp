#include "compression.hpp"

#include <iostream>
#include <algorithm>

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, width>, height>& getGray) {

std::vector<std::pair<uint8_t, uint8_t>> smallMap;

for (const auto& everyRow : getGray) {

    auto firstIt = everyRow.begin();

    while (firstIt != everyRow.end()) {

        auto secondIt = std::find_if_not(firstIt,everyRow.end(), [firstIt](int x){return x == *firstIt;});
        smallMap.emplace_back(std::make_pair(*firstIt,std::distance(firstIt, secondIt)));
        firstIt = secondIt;
    }
}

return smallMap;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>> Compressed) {

std::array<std::array<uint8_t, width>, height> result {};

auto it = Compressed.begin();
auto decompress = [&](){
    if(it->second){
        it->second--;
        return it->first;
    }
    it++;
    it->second--;
    return it->first;
};

for(auto& row : result){
    std::generate(row.begin(), row.end(), decompress);
}

return result;
}

void printMap(const std::array<std::array<uint8_t, width>, height>& getMap) {

    for(auto everyRow : getMap) {

        for(auto element : everyRow) {

            if(element <= ' ') {
                std::cout << " ";
            } else {
                std::cout << element;
            }
        }
        std::cout << "\n";
    }
}
