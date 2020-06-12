#include "compression.hpp"

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, width>, height>& bitmap) {
    std::vector<std::pair<uint8_t, uint8_t>> compressedData;

    compressedData.reserve(width * height);

    size_t i, j, counter = 1;

    for (i = 0; i < height; i++) {
        for (j = 0; j < width - 1; j++) {
            if (bitmap[i][j] != bitmap[i][j + 1]) {
                compressedData.emplace_back(bitmap[i][j], counter);
                counter = 1;
            } else {
                counter++;
            }
        }
        compressedData.emplace_back(bitmap[i][j], counter);
        counter = 1;
    }
    compressedData.shrink_to_fit();

    return compressedData;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(const std::vector<std::pair<uint8_t, uint8_t>>& compressedBitmap) {
    uint8_t currWidth = 0, row = 0;
    std::array<std::array<uint8_t, width>, height> decompressedData;

    for (const auto& el : compressedBitmap) {
        for (size_t i = currWidth; i < currWidth + el.second; i++) {
            decompressedData[row][i] = el.first;
        }
        currWidth += el.second;
        if (currWidth == width) {
            currWidth = 0;
            row++;
        }
    }

    return decompressedData;
}
