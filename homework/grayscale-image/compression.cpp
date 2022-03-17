#include <iostream>
#include "compression.hpp"

compressedType compressGrayscale(bitmapType& pgm) {
    compressedType output;
    output.reserve(height * width);

    for(auto el : pgm) {
        uint8_t value = el.front();
        uint8_t count = 0;
        auto previousEl = el.cbegin();
        for(auto it = el.begin(); it < el.cend(); ++it) {
            if (value != *it) { 
                output.push_back(std::make_pair(value, count));
                count = 1;
                value = *it;
            } else {
                count++;
            }
            if (it + 1 == el.cend()) {
                output.push_back(std::make_pair(value, count));
            }
        }
    }
    return output;
}

bitmapType decompressGrayscale(compressedType& compressedImage) {
    bitmapType output;
    auto row = 0;
    auto column = 0;
    for(auto& el : compressedImage) {
        for(uint8_t i = 0; i < el.second; ++i) {
            output.at(row).at(column) = el.first;
            ++column;
        }
        if(column == width) {
            ++row;
            column = 0;
        }
    }
    return output;
}