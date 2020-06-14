#include "compression.hpp"

#include <iostream>

VectorPair compressGrayscale(const ArrayArray& data) {
    VectorPair result;

    for (const auto& entry : data) {
        // TO DO
    }

    return result;
}

ArrayArray decompressGrayscale(const VectorPair& data) {
    ArrayArray result;

    for (const auto& entry : data) {
        // TO DO
    }

    return result;
}

void printMap(ArrayArray& data) {
    constexpr uint8_t delim = 32;
    for (const auto& colData : data) {
        for (const auto& rowData : colData) {
                std::cout << ((rowData > delim) ? rowData : delim);
        }
        std::cout << '\n';
    }
}
