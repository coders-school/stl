#include "compression.hpp"

#include <iostream>

VectorPair compressGrayscale(const ArrayArray& data) {
    VectorPair result;
    result.reserve(width * height);

    for (const auto& entry : data) {
        uint8_t currValue = entry.front();
        uint8_t currCount = 1;

        for (uint8_t id = 1; id < width; id++) {
            if (entry[id] == currValue) {
               currCount++;
            } else { 
                result.emplace_back(std::make_pair(currValue, currCount));
                currValue = entry[id];
                currCount = 1;
            }
        }
        result.emplace_back(std::make_pair(currValue, currCount));
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
        } else {
            colCount = 0;
            rowId++;
            it = result[rowId].begin();
        }
    }

    return result;
}

void printMap(const ArrayArray& data) {
    constexpr uint8_t delim = 32;
    for (const auto& colData : data) {
        for (const auto& rowData : colData) {
                std::cout << ((rowData > delim) ? rowData : delim);
        }
        std::cout << '\n';
    }
    std::cout << "\n\n";
}
