#include "compression.hpp"

#include <iostream>

constexpr uint8_t ASCIIspace = 32;

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, width>, height>& dataToCompress) {
    std::vector<std::pair<uint8_t, uint8_t>> vecCompressed;

    return vecCompressed;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(const std::vector<std::pair<uint8_t, uint8_t>>& dataTodecompress) {
    std::array<std::array<uint8_t, width>, height> arrayDecompressed;

    return arrayDecompressed;
}

void printMap(const std::array<std::array<uint8_t, height>, width>& mapToPrint) {
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
