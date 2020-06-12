#include "compression.hpp"

#include <iostream>

CompressedBitmap compressGrayscale(const Bitmap& bitmap) {
    CompressedBitmap compressed;
    for (const auto& line : bitmap) {
        uint8_t count{};
        uint8_t pixel = line.front();
        for (auto el : line) {
            if (pixel == el) {
                ++count;
            } else {
                compressed.push_back({pixel, count});
                count = 1;
                pixel = el;
            }
        }
        compressed.push_back({pixel, count});
    }

    return compressed;
}

Bitmap decompressGrayscale(const CompressedBitmap& compressed) {
    Bitmap bitmap;

    size_t count{}, line{}, el{};

    for (const auto& pair : compressed) {
        if (count >= width) {
            count = 0;
            el = 0;
            ++line;
        }
        for (size_t i = 0; i < pair.second; ++i) {
            bitmap[line][el++] = pair.first;
        }
        count += pair.second;
    }

    return bitmap;
}

void printMap(const Bitmap& bitmap) {
    for (const auto& line : bitmap) {
        for (auto el : line) {
            if(el < ' ') {
                std::cout << ' ';
            } else {
                std::cout << el;
            }
        }
        std::cout << '\n';
    }
}
