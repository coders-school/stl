#include "compression.hpp"

#include <iostream>
#include <algorithm>

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height>& getGray) {

std::vector<std::pair<uint8_t, uint8_t>> smallMap;

std::transform(getGray.begin(), getGray.end(), getGray.begin(),
              [&smallMap](std::array<uint8_t,width> a){

              uint8_t currentNum = a[0];
              int counter = 0;

              std::transform(a.begin(), a.end(), a.begin(),
              [&smallMap, &currentNum, &counter](uint8_t var) {

                  if (var == currentNum) {

                    ++counter;
                    currentNum = var;

                  } else {

                    smallMap.emplace_back(std::make_pair(currentNum,counter));

                    counter = 1;
                    currentNum = var;

                  }

              return var;

              });

              smallMap.emplace_back(std::make_pair(currentNum,counter));

              return a;

              });

return smallMap;

}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>> compressedMap) {

    std::array<std::array<uint8_t, width>, height> result;

    auto iter = result[0].begin();

    std::transform(compressedMap.begin(), compressedMap.end(), compressedMap.begin(),
        [&iter](const auto& myPair) mutable {

            iter = std::fill_n(iter, myPair.second, myPair.first);
            return myPair;

    });

    return result;

}

void printMap(std::array<std::array<uint8_t, width>, height>& getMap) {

    std::transform(getMap.begin(), getMap.end(),getMap.begin(), [](auto& a){

        std::transform(a.begin(), a.end(), a.begin(), [](auto& el){

            if(el <= ' ') {
                std::cout << " ";
            } else {
                std::cout << el;
            }

            return el;

        });
        std::cout << "\n";

        return a;

    });

}
