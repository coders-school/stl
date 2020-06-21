#include "compression.hpp"

#include <algorithm>
#include <iostream>
#include <sstream>

CompressedPGMBitMap compressGrayscale(const PGMBitMap& img) {
    CompressedPGMBitMap bitMap;
    bitMap.reserve(height * width);

    for (const auto& row : img) {
        for (auto i = row.begin(); i != row.end();) {
            if (i != row.end()) {
                auto id = std::find_if_not(i, row.end(),
                                           [i](Pixel next) {
                                               return *i == next;
                                           });
                auto dist = std::distance(i, id);
                bitMap.push_back(std::make_pair(*i, dist));
                i = id;
            }
        }
    }
    bitMap.shrink_to_fit();
    return bitMap;
}

PGMBitMap decompressGrayscale(const CompressedPGMBitMap& compressedImg) {
    PGMBitMap decompressed;

    auto currentEmptySlot = decompressed.front().begin();

    for (const auto& pair : compressedImg) {
        currentEmptySlot = std::fill_n(currentEmptySlot, pair.second, pair.first);
    }

    return decompressed;
}

void printMap(const PGMBitMap& img) {
    std::stringstream ss;
    for (const auto& row : img) {
        for (const Pixel pixel : row) {
            ss << static_cast<char>(isprint(pixel) ? pixel : ' ');
        }
        ss << '\n';
    }
    std::cout << ss.str();
}
