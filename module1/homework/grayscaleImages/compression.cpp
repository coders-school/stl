#include "compression.hpp"
#include <algorithm>
#include <iostream>

CompressedBitmap compressGrayscale(const Bitmap& bitmap) {
    CompressedBitmap compressedBitmap;
    compressedBitmap.reserve(height * width);
    for (const auto& row : bitmap) {
        uint8_t color{row.front()};
        std::size_t consecutiveCounter{1};
        for (auto it = row.begin(); it != row.end(); ++it) {
            auto nextBitColor = std::next(it);
            if (color != *nextBitColor || nextBitColor == row.end())
            {
                compressedBitmap.emplace_back(color, consecutiveCounter);
                consecutiveCounter = 1;
                color = *nextBitColor;
            }
            else
            {
                ++consecutiveCounter;
            }
        }
    }
    compressedBitmap.shrink_to_fit();
    return compressedBitmap;
}

Bitmap decompressGrayscale(const CompressedBitmap& compressedBitmap) {
    Bitmap decompressedBitmap;
    size_t currentRow{0};
    size_t currentColumn{0};
    for (const auto& colorChunk : compressedBitmap) {
        for(size_t consecutiveCounter = 0; consecutiveCounter < colorChunk.second; ++consecutiveCounter){
            decompressedBitmap[currentRow][currentColumn] = colorChunk.first;
            if (currentColumn < width - 1) {
                currentColumn++;
            }
            else {
                currentRow++;
                currentColumn = 0;
            } 
        }
    }
    return decompressedBitmap;
}