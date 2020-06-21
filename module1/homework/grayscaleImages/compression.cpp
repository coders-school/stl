#include "compression.hpp"
#include <algorithm>
#include <iostream>

CompressedBitmap compressGrayscale(const Bitmap& bitmap) {
    CompressedBitmap compressedBitmap;
    compressedBitmap.reserve(height * width);
    for (const auto& row : bitmap) {
        for (auto currentColorIt = row.begin(); currentColorIt != row.end();) {
            const auto diffColorIt = std::find_if(currentColorIt, 
                                                  row.end(), 
                                                  [&](const auto& color) { 
                                                      return color != *currentColorIt; 
                                                  });
            compressedBitmap.emplace_back(*currentColorIt, std::distance(currentColorIt, diffColorIt));
            currentColorIt = diffColorIt;
        }    
    }
    compressedBitmap.shrink_to_fit();
    return compressedBitmap;
}

Bitmap decompressGrayscale(const CompressedBitmap& compressedBitmap) {
    Bitmap decompressedBitmap;
    auto it = (decompressedBitmap.front()).begin();
    for (const auto& colorChunk : compressedBitmap) {
        it = std::fill_n(it, colorChunk.second, colorChunk.first);
    }
    return decompressedBitmap;
}
