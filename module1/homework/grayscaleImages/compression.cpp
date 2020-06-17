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
    auto row = bitmap.begin();
    auto col = row->begin();

    for (const auto& pair : compressed) {
        if (col >= row->end()) {
            row++;
            col = row->begin();
        }
        col = std::fill_n(col, pair.second, pair.first);
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
