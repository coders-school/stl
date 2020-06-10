#include "compression.hpp"

compressed_bitmap compressGrayscale(const bitmap& image) {
    compressed_bitmap compressedImage{};
    compressedImage.reserve(height * width);

    for (const auto& el : image) {
        uint8_t counter = 1;
        for (auto it = el.begin(); it != el.end(); ++it) {
            auto next_element = std::next(it);
            if (*it != *next_element or next_element == el.end()) {
                compressedImage.push_back({*it, counter});
                counter = 1;
            } else {
                counter++;
            }
        }
    }
    compressedImage.shrink_to_fit();
    return compressedImage;
}

/* This is awful 
 I am waiting for help, other people solutions
*/

bitmap decompressGrayscale(const compressed_bitmap& compressedImage) {
    bitmap result{};
    auto currentRow = 0;
    auto it = compressedImage.begin();
    for (size_t i = 0; i < height; ++i) {
        std::array<uint8_t, width> tempRow{};
        for (size_t j = 0; j < width;) {
            for (size_t k = 0; k < it->second; ++k) {
                tempRow[j + k] = it->first;
            }
            j += it->second;
            std::advance(it, 1);
        }
        result[i] = tempRow;
    }

    return result;
}
