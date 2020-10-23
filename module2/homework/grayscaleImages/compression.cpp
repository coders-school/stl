#include "compression.hpp"

#include <algorithm>
#include <cctype>
#include <iostream>

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height>& getGray)
{
    std::vector<std::pair<uint8_t, uint8_t>> smallMap;
    smallMap.reserve(width * height);

    std::transform(getGray.begin(), getGray.end(), getGray.begin(),

                   [&smallMap](std::array<uint8_t, width> everyRow) {
                       auto firstIt = everyRow.begin();
                       while (firstIt != everyRow.end()) {
                           auto secondIt = std::find_if_not(firstIt, everyRow.end(), [firstIt](int x) { return x == *firstIt; });
                           smallMap.emplace_back(*firstIt, std::distance(firstIt, secondIt));
                           firstIt = secondIt;
                       }

                       return everyRow;
                   });

    smallMap.shrink_to_fit();
    return smallMap;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>> compressedMap)
{
    std::array<std::array<uint8_t, width>, height> result;

    auto iter = result.front().begin();

    std::transform(compressedMap.begin(), compressedMap.end(), compressedMap.begin(),
                   [&iter](const auto& myPair) mutable {
                       iter = std::fill_n(iter, myPair.second, myPair.first);
                       return myPair;
                   });
    return result;
}

void printMap(std::array<std::array<uint8_t, width>, height>& getMap)
{
    std::transform(getMap.begin(), getMap.end(), getMap.begin(), [](auto& a) {
        std::transform(a.begin(), a.end(), a.begin(), [](auto& el) {
            if (isprint(el) == 0) {
                std::cout << " ";
            }
            else {
                std::cout << el;
            }

            return el;
        });
        std::cout << "\n";
        return a;
    });
}
