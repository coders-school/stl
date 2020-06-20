#include "compression.hpp"

#include <algorithm>
#include <iostream>
#include <string>

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(
    const std::array<std::array<uint8_t, height>, width>& uncompressed) {
    std::vector<std::pair<uint8_t, uint8_t>> compressed;
    compressed.reserve(height * width);

    std::for_each(uncompressed.begin(), uncompressed.end(), [&](auto row) {
        auto groupBegin = row.begin();
        auto nextGroupBegin = row.end();

        do {
            uint8_t firstPixelInGroup = *groupBegin;
            nextGroupBegin =
                std::find_if_not(groupBegin,
                                 row.end(),
                                 [&](auto currentPixel) {
                                     return currentPixel == firstPixelInGroup;
                                 });

            auto groupSize = std::distance(groupBegin, nextGroupBegin);
            compressed.push_back(std::make_pair(*groupBegin, groupSize));
            groupBegin = nextGroupBegin;
        } while (nextGroupBegin != row.end());
    });

    compressed.shrink_to_fit();
    return compressed;
}

std::array<std::array<uint8_t, height>, width> decompressGrayscale(
    const std::vector<std::pair<uint8_t, uint8_t>>& compressed) {
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

void printMap(std::array<std::array<uint8_t, height>, width>& bitmap) {
    const std::string palette = R"( .'`^",:;Il!i><~+_-?][}{1)(|\/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao*#MW&8%B@$)";
    int level;
    const double normalizingFactor = palette.size() / 256.0;
    std::cout << "\n";

    for (auto& row : bitmap) {
        for (auto& pixel : row) {
            level = pixel * normalizingFactor;
            std::cout << palette[level];
        }
        std::cout << "\n";
    }
}
