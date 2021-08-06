#include "compression.hpp"

#include <algorithm>
#include <iostream>
#include <iterator>

CompressedBitmap compressGrayscale(const Bitmap& bitmap) {
    CompressedBitmap compressed;
    uint8_t nextPixel = ' ';
    auto compare = [&](uint8_t pixel) {
        if (pixel != nextPixel) {
            std::ranges::fill_n(std::back_inserter(compressed), 1, std::make_pair(pixel, 1));
        } else {
            compressed[compressed.size() - 1].second += 1;
        }
        nextPixel = pixel;
    };
    std::ranges::for_each(bitmap,
                          [&](auto line) { nextPixel = ' '; std::for_each(begin(line),
                                                 end(line), compare); });
    return compressed;
}

Bitmap decompressGrayscale(CompressedBitmap& compressed) {
    Bitmap bitmap;
    auto it = begin(bitmap)->begin();
    std::ranges::for_each(compressed,
                          [&it](auto ele) { std::ranges::fill_n(it, 
                                               ele.second, ele.first); 
                                               it = std::next(it, ele.second); });
    return bitmap;
}

void printMap(const Bitmap& bitmap) {
    std::for_each(begin(bitmap)->begin(),
                  end(bitmap)->end(),
                  [index = 0](auto ch) mutable { 
                                                index++; 
                                                std::cout << static_cast<char>(ch < printable_ascii_min || ch > printable_ascii_max ? ' ' : ch); 
                                                if(index >= 32) {  index = 0; std::cout << '\n';
                                            } });
}
