#include "compression.hpp"

#include <algorithm>
#include <iostream>
#include <map>

compressedBitmap compressGrayscale(image& img) {
    compressedBitmap cb{};

    for (const auto& row : img) {
        for (const auto col : row) {
            if (cb.empty() || cb.back().first != col) {
                cb.emplace_back(std::make_pair(col, 1));
            } else {
                ++cb.back().second;
            }
        }
    }
    cb.shrink_to_fit();

    return cb;
}

image decompressGrayscale(compressedBitmap& bmp) {
    image reconstrucedImage{};
    for (size_t i = 0; i < height; i++) {
        for (size_t j = 0; j < width; j++) {
        }
    }

    return reconstrucedImage;
}