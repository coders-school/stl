#include "compression.hpp"

#include <algorithm>
#include <iostream>
#include <iterator>

CompressedBitmap compressGrayscale(const Bitmap& bitmap) {
    CompressedBitmap compressed(width * height, std::make_pair(0, 0));
    uint8_t counter = 0;
    uint8_t counterLine = 0;
    auto iter = begin(bitmap)->begin();
    std::transform(iter, 
                   (end(bitmap) - 1)->end(), 
                   begin(compressed), 
                   [&](auto pixel) { 
                       if (counterLine == height){
                           counterLine = 0;
                           counter = 0;
                       }
                       if (pixel != *std::prev(iter)) {
                           counter = 1;
                       } else {
                           counter++;
                       }                       
                       counterLine++;
                       iter++;
                       return std::make_pair(pixel, counter); 
                   });
    auto it = begin(compressed);
    compressed.erase(std::remove_if(begin(compressed), 
                                    end(compressed), 
                                    [&](auto ele){ 
                                        it++; 
                                        return ele.first == (*it).first && ele.second == (*it).second - 1; }), 
                     end(compressed));
    return compressed;
}

Bitmap decompressGrayscale(CompressedBitmap& compressed) {
    std::cout << " Call DECOMPRESSED \n";
    Bitmap bitmap{};

    // for ( auto ele : compressed) {
    //     std::cout << "(" << static_cast<int>(ele.first) << ", " << static_cast<int>(ele.second) << ")   ";
    // }
    auto it = begin(bitmap)->begin();
    std::for_each(begin(compressed),
                          end(compressed), 

                          [&it](auto ele) { std::fill_n(it, 
                                               ele.second, ele.first); 
                                               it = std::next(it, ele.second); });
    //std::cout << bitmap.size() << "----------------------------------------------------------------\n";
    return bitmap;
}

// Bitmap decompressGrayscale(CompressedBitmap& compressed) {
//     Bitmap bitmap{};
//     size_t line{};
//     auto pixel_it{bitmap[line].begin()};
//     for (const auto& pair : compressed) {
//         if (pixel_it >= bitmap[line].end()) {
//             pixel_it = bitmap[++line].begin();
//         }
//         for (auto i = 0; i < pair.second; ++i) {
//             *pixel_it++ = pair.first;
//         }
//     }

//     return bitmap;
// }

// void printMap(const Bitmap& bitmap) {
//     std::cout << " Call PRINT \n";
//     int test = 0;
//     std::for_each(begin(bitmap)->begin(),
//                   (end(bitmap) - 1)->end(),
//                   [&test, index = 0](auto ch) mutable { 
//                                                 index++; 
//                                                 std::cout << static_cast<char>(ch < printable_ascii_min || ch > printable_ascii_max ? ' ' : ch); 
//                                                 if(index >= 32) {  index = 0; std::cout << '\n';
//                                             } });
// }

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
