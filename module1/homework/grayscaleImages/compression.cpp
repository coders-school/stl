#include "compression.hpp"

#include <algorithm>
#include <cctype>
#include <iostream>

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, width>, height>& bitmap) {
    std::vector<std::pair<uint8_t, uint8_t>> compress;

    uint8_t color;
    std::for_each(bitmap.begin(), bitmap.end(), [&color, &compress](const auto& row){
            color = row.front();
            auto it_first = row.begin();

            while(it_first != row.end()) {
                auto it_second = std::find_if(it_first, row.end(), [&color](auto pixel){ return pixel != color; });
                compress.push_back({color, it_second - it_first});
                it_first = it_second;
                color = *it_second;
            }
    });

    return compress;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(const std::vector<std::pair<uint8_t, uint8_t>>& bitmap) {
    std::array<std::array<uint8_t, width>, height> decompress;

    auto it = bitmap.begin();
    for(size_t row = 0; row < height; ++row) {
        auto decomp_it = decompress[row].begin();

        while(decomp_it != decompress[row].end()) {
            std::fill_n(decomp_it, it->second, it->first);
            decomp_it += it->second;
            ++it;
        }
    }

    return decompress;
}

void printMap(const std::array<std::array<uint8_t, width>, height>& bitmap) {
    for(const auto& row : bitmap) {
        for(const auto& column : row) {
            if(std::isprint(column)) {
                std::cout << column;
            } else {
                std::cout << ' ';
            }
        }
        std::cout << '\n';
    }
    
}
