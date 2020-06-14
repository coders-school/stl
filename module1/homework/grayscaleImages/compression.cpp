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

    size_t pairCounter = 0;
    HeightType currentRow = 0;
    size_t idxWithinRow = 0;
    auto currentEmptySlot = decompressed[currentRow].begin();

    for (const auto& pair : compressedImg) {
        pairCounter++;

        if (pair.second > (width - idxWithinRow)) {
            throw std::invalid_argument("Pair #" + std::to_string(pairCounter) + " overflows a single row, which is not allowed in compression algorithm");
        }
        if (currentRow >= height) {
            throw std::invalid_argument("Pair #" + std::to_string(pairCounter) + " tries to fill a row exceeding image height, which is not allowed");
        }
        auto placeToFillTo = std::next(currentEmptySlot, pair.second);
        std::fill(currentEmptySlot, placeToFillTo, pair.first);
        idxWithinRow += pair.second;
        if (idxWithinRow < width) {
            currentEmptySlot = placeToFillTo;
        } else {
            idxWithinRow = 0;
            currentRow++;
            currentEmptySlot = decompressed[currentRow].begin();
        }
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
