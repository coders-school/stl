#include <algorithm>
#include <iostream>
#include <utility>

#include "compression.hpp"

std::vector<uint8_tPair> compressGrayscale(bitmapType& bitmap) {
    std::vector<uint8_tPair> compressedData;
    compressedData.reserve(width * height);

    std::all_of(bitmap.begin(), bitmap.end(),
        [&compressedData](const auto& row) mutable {
                auto current = row.begin();
                std::all_of(row.begin(),row.end(),
                    [&current,&row,&compressedData](const auto& el){
                        if(current != row.end()) {
                            uint8_t color = *current;
                            auto index = std::find_if_not(current, row.end(),
                            [color](uint8_t other){
                                return color == other;
                            });
                            auto occurrence = std::distance(current, index);
                            compressedData.push_back({color, occurrence});
                            current = index;
                        }
                        return true;
                    });
                return true;
    });

    compressedData.shrink_to_fit();
    return compressedData;
}

compressedArray decompressGrayscale(std::vector<uint8_tPair>& compressedData) {
    compressedArray bitmap;
    std::array<uint8_t, width> row;
    std::all_of(compressedData.begin(), compressedData.end(),
        [rowNum = 0, pos = 0, row, &bitmap](const auto& elem) mutable {
            std::fill_n(std::next(row.begin(), pos), elem.second, elem.first);
            pos += elem.second;
            if (pos >= width) {
                bitmap[rowNum++] = row;
                pos = 0;
            }
            return true;
     });
    return bitmap;
}

void printMap(imageBitmap& bitmap) {
    std::all_of(bitmap.begin(), bitmap.end(), 
        [](std::array<uint8_t, imageWidth>& row){
            std::all_of(row.begin(), row.end(), 
                [](uint8_t& el){
                    std::cout << el << '\n';
                    return true;
                }
            );
            std::cout << '\n';
            return true;
        }
    );
}
