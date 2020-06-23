#include "compression.hpp"

#include <algorithm>
#include <cstdint>

compressedImage compressGrayscale(const Image& bitmap) {
    std::vector<std::pair<uint8_t, uint8_t>> compressed_bitmap;
    compressed_bitmap.reserve(width * height);
    uint8_t counter = 1;
    for (const auto& row : bitmap) {
        const uint8_t* beginning = row.begin();
        const uint8_t* end = row.begin();
        while (end != row.end()) {
            end = std::find_if(end, row.end(), [end](auto elem) {
                return *end != elem;
            });
            counter = std::distance(beginning, end);
            compressed_bitmap.push_back(std::make_pair(*beginning, counter));
            beginning = end;
        }
    }
    compressed_bitmap.shrink_to_fit();
    return compressed_bitmap;
}

Image decompressGrayscale(compressedImage& comp_b) {
    std::array<std::array<uint8_t, width>, height> decompressed_bitmap;
    int shade_counter = 0;
    int row = 0;

    for (auto el : comp_b) {
        for (size_t i = shade_counter; i < shade_counter + el.second; ++i) {
            decompressed_bitmap[row][i] = el.first;
        }
        shade_counter += el.second;
        if (shade_counter == width) {
            shade_counter = 0;
            ++row;
        }
    }

    return decompressed_bitmap;
};
