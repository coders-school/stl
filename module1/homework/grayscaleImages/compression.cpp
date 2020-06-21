#include "compression.hpp"

#include <iostream>
#include <string>

CompressedImage compressGrayscale(const UncompressedImage& uncompressed) {
    CompressedImage compressed;
    compressed.reserve(height * width);

    for (const auto& row : uncompressed) {
        uint8_t currentValueCounter = 1;
        for (auto it = row.begin(); it < row.end(); it++) {
            if (it == std::prev(row.end()) || *(it + 1) != *it) {
                compressed.push_back(std::make_pair(*it, currentValueCounter));
                currentValueCounter = 1;
            } else {
                currentValueCounter++;
            }
        }
    }
    compressed.shrink_to_fit();
    return compressed;
}

UncompressedImage decompressGrayscale(const CompressedImage& compressed) {
    UncompressedImage uncompressed;
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

void printMap(const UncompressedImage& bitmap) {
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
