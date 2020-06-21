#include "compression.hpp"

#include <iostream>
#include <algorithm>

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height>& getGray) {

std::vector<std::pair<uint8_t, uint8_t>> smallMap;

std::transform(getGray.begin(), getGray.end(), getGray.begin(),
              [&smallMap](std::array<uint8_t,width> a){

              uint8_t currentNum = a[0];
              int count = 0;

              std::transform(a.begin(), a.end(), a.begin(),
              [&smallMap, &currentNum, &count, &a](uint8_t var) {

                  if (var == currentNum) {

                    ++count;
                    currentNum = var;

                  } else {

                    smallMap.emplace_back(std::make_pair(currentNum,count));

                    count = 1;
                    currentNum = var;

                  }

              return var;

              });

              smallMap.emplace_back(std::make_pair(currentNum,count));

              return a;

              });

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
