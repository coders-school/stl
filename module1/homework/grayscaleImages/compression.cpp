#include "compression.hpp"

#include <iomanip>
#include <iostream>
#include <sstream>

CompressedPGMBitMap compressGrayscale(const PGMBitMap& img) {
    CompressedPGMBitMap bitMap;
    bitMap.reserve(height * width);

    for (const auto& row : img) {
        WidthType consecutiveCount = 0;

        for (uint8_t i = 0; i < width; i++) {
            consecutiveCount++;
            if (i == width -1 or row[i+1] != row[i]){
                bitMap.emplace_back(std::make_pair(row[i], consecutiveCount));
                consecutiveCount = 0;
            }
        }
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
