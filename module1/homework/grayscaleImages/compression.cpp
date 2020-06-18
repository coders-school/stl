#include "compression.hpp"

#include <algorithm>
#include <iostream>

pairVector compressGrayscale(const twoDimensionalArray& inputMap) {
    pairVector outputVec;
    outputVec.reserve(width * height);

    std::all_of(inputMap.begin(), inputMap.end(),
                [&outputVec](auto mapRow) {
                    for (auto tempIt = mapRow.begin(); tempIt != mapRow.end(); ++tempIt) {
                        auto it = std::adjacent_find(tempIt, mapRow.end(), std::not_equal_to<int>{});
                        if (it == mapRow.end()) {
                            it--;
                        }
                        outputVec.emplace_back(std::make_pair(*it, (std::distance(tempIt, it) + 1)));
                        tempIt = it;
                    }

                    return true;
                });
    outputVec.shrink_to_fit();
    return outputVec;
}

twoDimensionalArray decompressGrayscale(const pairVector& inputVec) {
    twoDimensionalArray outputArr;
    size_t rowCounter = 0;
    size_t columnCounter = 0;

    std::all_of(inputVec.begin(), inputVec.end(),
                [&rowCounter, &columnCounter, &outputArr](auto pair) {
                    if (rowCounter < height) {
                        for (size_t pairValue = 0; pairValue < pair.second; ++pairValue) {
                            outputArr[rowCounter][columnCounter] = pair.first;
                            if (columnCounter < width - 1)
                                columnCounter++;
                            else {
                                columnCounter = 0;
                                rowCounter++;
                            }
                        }
                    }
                    return true;
                });
    return outputArr;
}

void printMap(const twoDimensionalArray& inputMap) {
    std::all_of(inputMap.begin(), inputMap.end(), [](auto mapRow) {
        std::all_of(mapRow.begin(), mapRow.end(), [](auto rowElement) {
            std::cout << rowElement;
            return true;
        });
        std::cout << '\n';
        return true;
    });
}
