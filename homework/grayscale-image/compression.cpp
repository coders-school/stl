#include <algorithm>
#include <iostream>
#include "compression.hpp"


std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, width>, height>& image_array) {
    std::vector<std::pair<uint8_t, uint8_t>> compressed;
    compressed.reserve(width * height);

    std::for_each(image_array.begin(), image_array.end(),[&compressed](auto& row){
                    int vecPlace = 0;
                    for(auto It = row.begin(); It != row.end();) {
                        compressed.push_back(std::make_pair(*It, std::count_if(It, row.end(), [&It](auto& el){return el == *It;})));
                        It += compressed[vecPlace].second;
                        vecPlace++;
                    }
    });

    compressed.shrink_to_fit();
    return compressed;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(const std::vector<std::pair<uint8_t, uint8_t>>& image_vector) {
    std::array<std::array<uint8_t, width>, height> decompressed;
    int vectorPlace = 0;
    std::generate(decompressed.begin(), decompressed.end(), [&](){
        std::array<uint8_t, width> row;
        for (int amount = 0; row.size() != amount;) {
            std::fill_n(row.begin() + amount, image_vector[vectorPlace].second, image_vector[vectorPlace].first);
            amount += image_vector[vectorPlace].second;
            vectorPlace++;
        }
        return row;
    });
    return decompressed;
}

