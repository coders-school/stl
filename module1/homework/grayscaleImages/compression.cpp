#include "compression.hpp"
#include <iostream>

compressed_bitmap compressGrayscale(const bitmap& image) {
    compressed_bitmap compressedImage{};
    compressedImage.reserve(height * width);

    for (const auto& el : image) {
        for (auto it = el.begin(); it != el.end();) {
            auto newIt = std::adjacent_find(it, el.end(), std::not_equal_to<uint8_t>());
            if (newIt != el.end()) {
                newIt++;
            }
            uint8_t distance = std::distance(it, newIt);
            compressedImage.push_back({*it, distance});
            std::advance(it, distance);
        }
    }
    compressedImage.shrink_to_fit();
    return compressedImage;
}

bitmap decompressGrayscale(const compressed_bitmap& compressedImage) {
    bitmap result{};
    std::array<uint8_t, width> tempRow{};
    auto col = result.begin()->begin();
    std::for_each(compressedImage.begin(), compressedImage.end(),
                  [col](const std::pair<uint8_t, uint8_t>& aPair) mutable {
                      col = std::fill_n(col, aPair.second, aPair.first);
                  });

    return result;
}

void printMap(const bitmap& image) {
    for (const auto& row : image) {
        for (const auto& col : row) {
            !iscntrl(col) ? std::cout << col : std::cout << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n\n";
}
