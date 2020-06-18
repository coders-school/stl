#include "compression.hpp"

#include <algorithm>
#include <iostream>

pairVector compressGrayscale(const twoDimensionalArray& inputMap) {
    pairVector outputVec;
    outputVec.reserve(width * height);

    std::all_of(inputMap.begin(), inputMap.end(), [&outputVec](auto mapRow, int value = 0, int column = 0) {
        uint8_t color = mapRow.front();
        std::all_of(mapRow.begin(), mapRow.end(), [&color, &value, &column, &outputVec](auto rowElement) {
            if (rowElement != color || column == width - 1) {
                if (column == width - 1)
                    value++;
                outputVec.emplace_back(std::make_pair(color, (value)));
                value = 1;
                color = rowElement;
            } else {
                value++;
            }
            column++;
            return true;
        });
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
