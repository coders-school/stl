#include "compression.hpp"

#include <iostream>
#include <string>

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(
    const std::array<std::array<uint8_t, height>, width>& uncompressed) {
    std::vector<std::pair<uint8_t, uint8_t>> compressed;
    compressed.reserve(height * width);

    for (const auto& row : uncompressed) {
        auto rowIterator = row.cbegin();
        uint8_t currentValue = *rowIterator;
        uint8_t currentValueCounter = 1;
        rowIterator++;

        while (rowIterator != row.cend()) {
            if (*rowIterator == currentValue) {
                currentValueCounter++;
            } else {
                compressed.push_back(std::make_pair(currentValue, currentValueCounter));
                currentValue = *rowIterator;
                currentValueCounter = 1;
            }
            rowIterator++;
        }
        // and when row reach end:
        compressed.push_back(std::make_pair(currentValue, currentValueCounter));
    }

    compressed.shrink_to_fit();
    return compressed;
}

std::array<std::array<uint8_t, height>, width> decompressGrayscale(
    const std::vector<std::pair<uint8_t, uint8_t>>& compressed) {
    std::array<std::array<uint8_t, height>, width> uncompressed;
    auto pixelGroup = compressed.begin();
    uint8_t pixelsToUnpack = pixelGroup->second;

    for (auto& row : uncompressed) {
        for (auto& pixel : row) {
            if (pixelsToUnpack == 0) {
                pixelGroup++;
                pixelsToUnpack = pixelGroup->second;
            }
            pixel = pixelGroup->first;
            pixelsToUnpack--;
        }
    }
    return uncompressed;
}

void printMap(const std::array<std::array<uint8_t, height>, width>& bitmap) {
    const std::string palette = R"( .'`^",:;Il!i><~+_-?][}{1)(|\/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao*#MW&8%B@$)";
    int level;
    const double normalizingFactor = palette.size() / 256.0;
    std::cout << "\n";

    for (const auto& row : bitmap) {
        for (const auto& pixel : row) {
            level = pixel * normalizingFactor;
            std::cout << palette[level];
        }
        std::cout << "\n";
    }
}
