#include "compression.hpp"

#include <algorithm>
#include <cctype>
#include <iostream>

SqueezedMap compressGrayscale(DiffusedMap& getGray)
{
    SqueezedMap squeezedMap;
    squeezedMap.reserve(width * height);

    std::transform(getGray.begin(), getGray.end(), getGray.begin(),

                   [&squeezedMap](std::array<uint8_t, width> everyRow) {
                       auto firstIt = everyRow.begin();
                       while (firstIt != everyRow.end()) {
                           auto secondIt = std::find_if_not(firstIt, everyRow.end(), [firstIt](int x) { return x == *firstIt; });
                           squeezedMap.emplace_back(*firstIt, std::distance(firstIt, secondIt));
                           firstIt = secondIt;
                       }

                       return everyRow;
                   });

    squeezedMap.shrink_to_fit();
    return squeezedMap;
}

DiffusedMap decompressGrayscale(SqueezedMap compressedMap)
{
    DiffusedMap diffusedMap;

    auto iter = diffusedMap.front().begin();

    std::transform(compressedMap.begin(), compressedMap.end(), compressedMap.begin(),
                   [&iter](const auto& myPair) mutable {
                       iter = std::fill_n(iter, myPair.second, myPair.first);
                       return myPair;
                   });
    return diffusedMap;
}

void printMap(DiffusedMap& getMap)
{
    std::transform(getMap.begin(), getMap.end(), getMap.begin(), [](auto& everyElement) {
        std::transform(everyElement.begin(), everyElement.end(), everyElement.begin(), [](auto& singleElement) {
            if (isprint(singleElement) == 0) {
                std::cout << " ";
            }
            else {
                std::cout << singleElement;
            }

            return singleElement;
        });
        std::cout << "\n";
        return everyElement;
    });
}
