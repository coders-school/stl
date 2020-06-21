#include "compression.hpp"

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, width>, height>& img) {
    std::vector<std::pair<uint8_t, uint8_t>> bitMap;
    bitMap.reserve(height * width);

    for (const auto& row : img) {
        for (auto i = row.begin(); i != row.end();) {
            if (i != row.end()) {
                auto id = std::find_if_not(i, row.end(),
                                           [i](uint8_t next) {
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

std::array<std::array<uint8_t, width>, height> decompressGrayscale(const std::vector<std::pair<uint8_t, uint8_t>>& compressedImg) {
    std::array<std::array<uint8_t, width>, height> decompressed;

    auto currentEmptySlot = decompressed.front().begin();

    for (const auto& pair : compressedImg) {
        currentEmptySlot = std::fill_n(currentEmptySlot, pair.second, pair.first);
    }

    return decompressed;
}

void printMap(const std::array<std::array<uint8_t, width>, height>& img) {
    std::stringstream ss;
    for (const auto& row : img) {
        for (const uint8_t pixel : row) {
            ss << static_cast<char>(isprint(pixel) ? pixel : ' ');
        }
        ss << '\n';
    }
    std::cout << ss.str();
}
