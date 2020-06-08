#include "compression.hpp"

#include <iostream>
#include <string>

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(
    std::array<std::array<uint8_t, height>, width> uncompressed) {
    std::vector<std::pair<uint8_t, uint8_t>> compressed;
    compressed.reserve(height * width);

    for (const auto row : uncompressed) {
        auto rowIterator = row.cbegin();
        uint8_t value = *rowIterator;
        uint8_t currentValueCounter = 1;
        rowIterator++;
        while (rowIterator != row.cend()) {
            if (*rowIterator == value) {
                currentValueCounter++;
            } else {
                compressed.push_back(std::make_pair(value, currentValueCounter));
                value = *rowIterator;
                currentValueCounter = 1;
            }
            rowIterator++;
        }
        // and for last value in a row:
        compressed.push_back(std::make_pair(value, currentValueCounter));
    }

    compressed.shrink_to_fit();

    double compressionRatio = (double)compressed.size() / (height * width);
    return compressed;
}

std::array<std::array<uint8_t, height>, width> decompressGrayscale(
    std::vector<std::pair<uint8_t, uint8_t>> compressed) {
    std::array<std::array<uint8_t, height>, width> uncompressed;
    auto pixelGroup = compressed.begin();

    uint8_t howManyPixels = pixelGroup->second;

    for (auto& row : uncompressed) {
        for (auto& pixel : row) {
            if (howManyPixels == 0) {
                pixelGroup++;
                howManyPixels = pixelGroup->second;
            }
            pixel = pixelGroup->first;
            howManyPixels--;
        }
    }
    return uncompressed;
}

void printMap(std::array<std::array<uint8_t, height>, width> bitmap) {
    const std::string palette = R"( .'`^",:;Il!i><~+_-?][}{1)(|\/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao*#MW&8%B@$)";
    palette;
    int level;
    for (auto& row : bitmap) {
        for (auto& pixel : row) {
            level = (pixel / 256.0) * palette.size();
            std::cout << palette[level];
        }
        std::cout << "\n";
    }
}