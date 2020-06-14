#include "compression.hpp"

#include <iostream>

constexpr uint8_t ASCIIspace = 32;

VectorPair compressGrayscale(const ArrayArray& data) {
    VectorPair result;
    result.reserve(width * height);

    for (const auto& entry : data) {
        uint8_t currValue = entry.front();
        uint8_t currCount = 1;

        for (uint8_t value : entry) {
            if (value == currValue) {
               currCount++;
            } else { 
                result.emplace_back({currValue, currCount});
                currValue = value;
                currCount = 1;
            }
        }
        result.emplace_back({currValue, currCount});
    }
    result.shrink_to_fit();

    return result;
}

ArrayArray decompressGrayscale(const VectorPair& data) {
    ArrayArray result;

    size_t colCount = 0;
    uint8_t rowId = 0;
    auto it = result[rowId].begin();

    for (const auto& entry : data) {
        auto it_back = std::next(it, entry.second);
        std::fill(it, it_back, entry.first);
        colCount += entry.second;
        if (colCount < width) {
            it = it_back;
        } else if (++rowId < height) {
            colCount = 0;
            it = result[rowId].begin();
        }
    }

    return result;
}

void printMap(const ArrayArray& mapToPrint) {
    for (const auto& column : mapToPrint) {
        for (const auto& rowValue : column) {
            if (rowValue > ASCIIspace) {
                std::cout << rowValue;
            } else {
                std::cout << ASCIIspace;
            }
        }
        std::cout << '\n';
    }
}
