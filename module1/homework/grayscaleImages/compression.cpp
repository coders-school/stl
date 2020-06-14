#include "compression.hpp"

#include <iomanip>
#include <iostream>
#include <sstream>

CompressedPGMBitMap compressGrayscale(const PGMBitMap& img) {
    CompressedPGMBitMap bitMap;
    bitMap.reserve(height * width);

    for (const auto& row : img) {
        Pixel lastValue = row[0];
        WidthType consecutiveCount = 1;

        for (uint8_t i = 1; i < width; i++) {
            if (row[i] != lastValue) {
                bitMap.emplace_back(std::make_pair(lastValue, consecutiveCount));
                lastValue = row[i];
                consecutiveCount = 1;
            } else {
                consecutiveCount++;
            }
        }
        bitMap.emplace_back(std::make_pair(lastValue, consecutiveCount));
    }
    bitMap.shrink_to_fit();
    return bitMap;
}

PGMBitMap decompressGrayscale(const CompressedPGMBitMap& compressedImg) {
    PGMBitMap decompressed;

    auto currentEmptySlot = decompressed[0].begin();

    for (const auto& pair : compressedImg) {
        auto placeToFillTo = std::next(currentEmptySlot, pair.second);
        std::fill(currentEmptySlot, placeToFillTo, pair.first);
        currentEmptySlot = placeToFillTo;

    }

    return decompressed;
}

void printMap(const PGMBitMap& img) {
    std::stringstream ss;
    for (const auto& row : img) {
        for (const Pixel pixel : row) {
            ss << std::setw(4) << std::setfill(' ') << std::to_string(pixel);
        }
        ss << '\n';
    }
    std::cout << ss.str();
}
