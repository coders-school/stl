#include "compression.hpp"

#include <algorithm>
#include <iostream>

CompressedBitmap compressGrayscale(const Bitmap& bitmap) {
    CompressedBitmap compressed;
    compressed.reserve(width * height);

    int row{};
    do {
        for (auto beg = bitmap[row].begin(),
                  end = bitmap[row].end();
             beg != end;) {
            const auto diff = std::find_if(beg, end,
                                           [&beg](const auto& el) {
                                               return el != *beg;
                                           });
            compressed.emplace_back(*beg, std::distance(beg, diff));
            beg = diff;
        }
    } while (++row != height);

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
            if (ch < min_print) {
                std::cout << ' ';
            } else {
                std::cout << ch;
            }
        }
        std::cout << '\n';
    }
}
