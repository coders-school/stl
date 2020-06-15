#include "compression.hpp"

#include <iostream>

CompressedBitmap compressGrayscale(const Bitmap& bitmap) {
    CompressedBitmap compressed;
    compressed.reserve(width * height);
    for (const auto& line : bitmap) {
        uint8_t count{1};
        uint8_t pixel = line.front();
        
        for (auto el = line.begin(); el != line.end(); ++el) {
            auto next = std::next(el);
            if (pixel != *next || next == line.end()) {
                compressed.push_back({pixel, count});
                pixel = *next;
                count = 1;
            } else {
                ++count;
            }
        }
    }
    compressed.shrink_to_fit();
    
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
        for (auto ch : line) {
            if(ch < min_print) {
                std::cout << ' ';
            } else {
                std::cout << ch;
            }
        }
        std::cout << '\n';
    }
}
