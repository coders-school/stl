#include "compression.hpp"

#include <iostream>

constexpr uint8_t ASCIIspace = 32;

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, width>, height>& dataToCompress) {
    std::vector<std::pair<uint8_t, uint8_t>> vecCompressed;
    for (const auto& arrayInVec : dataToCompress) {
        uint8_t counter = 0;
        for (auto it = arrayInVec.begin(); it != arrayInVec.end(); ++it) {
            if (*it == *std::next(it) && (std::next(it) != arrayInVec.end())) {
                counter++;
            }
            if (*it != *std::next(it) || (std::next(it) == arrayInVec.end())) {
                counter++;
                vecCompressed.push_back({*it, counter});
                counter = 0;
            }
        }
    }

    return vecCompressed;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(const std::vector<std::pair<uint8_t, uint8_t>>& dataTodecompress) {
    std::array<std::array<uint8_t, width>, height> arrayDecompressed;
    auto it = arrayDecompressed.front().begin();
    for (auto& el : dataTodecompress) {
        for (size_t i = 0; i < el.second; ++i) {
            *it = el.first;
            *it++;
        }
    }

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
