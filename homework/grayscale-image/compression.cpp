#include "compression.hpp"

#include <algorithm>
#include <iostream>
#include <iterator>

CompressedBitmap compressGrayscale(const Bitmap& bitmap) {
    CompressedBitmap compressed;
    auto compare = [&compressed](auto pixel, uint8_t counter = 1, uint8_t nextPixel = ' ') {
        if (pixel != nextPixel) {
            std::fill_n(std::back_inserter(compressed), 1, std::make_pair(pixel, counter));
        } else {
            counter++;
        }
        nextPixel = pixel;
    };

    std::for_each(begin(bitmap),
                  end(bitmap),
                  [&](auto line) { std::for_each(begin(line),
                                                 end(line), compare); });
    // for (auto i : compressed) {
    //     std::cout << i.first << " - " << i.second << "  .....  ";
    // }
    return compressed;
}

Bitmap decompressGrayscale(const CompressedBitmap& compressed) {
    Bitmap bitmap;
    std::transform(begin(compressed), end(compressed), bitmap.begin()->begin());


        // std::for_each(begin(bitmap),
        //           end(bitmap),
        //           [&](auto line) {  });


    size_t line{};
    auto pixel_it{bitmap[line].begin()};
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
                                                   ch > printable_ascii_max
                                               ? ' '
                                               : ch);
        }
        std::cout << std::endl;
    }
}
