#include "compression.hpp"

#include <iostream>

CompressedBitmap compressGrayscale(const Bitmap& bitmap) {
    CompressedBitmap compressed;
    compressed.reserve(width * height);
    for (const auto& line : bitmap) {
        uint8_t count{ 1 };
        uint8_t pixel{ line.front() };
        for (auto it = line.begin(); it != line.end(); ++it) {
            auto next_pixel_it{ std::next(it) };
            if (pixel != *next_pixel_it || next_pixel_it == line.end()) {
                compressed.push_back( {pixel, count} );
                pixel = *next_pixel_it;
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
    size_t line{};
    auto pixel_it{ bitmap[line].begin() };
    for (const auto& pair : compressed) {
        if (pixel_it >= bitmap[line].end()) {
            pixel_it = bitmap[++line].begin();
        }
        for (auto i = 0; i < pair.second; ++i) {
            *pixel_it++ = pair.first;
        }
    }

    return bitmap;
}

void printMap(const Bitmap& bitmap) {
    for (const auto& line : bitmap) {
        for (const auto ch : line) {
            std::cout << static_cast<char>(ch < printable_ascii_min ||
                                           ch > printable_ascii_max ? ' ' : ch);
        }
        std::cout << std::endl;
    }
}
