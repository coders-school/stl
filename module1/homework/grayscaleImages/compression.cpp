#include "compression.hpp"
#include <iostream>

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

bitmap decompressGrayscale(const compressed_bitmap& compressedImage) {
    bitmap result{};
    std::array<uint8_t, width> tempRow{};
    auto currentRow = 0;
    auto currentCol = 0;

    for (const auto& el : compressedImage) {
        for (uint8_t i = currentCol; i < el.second + currentCol; i++) {
            tempRow[i] = el.first;
        }
        currentCol += el.second;
        if (currentCol == width) {
            std::swap(result[currentRow], tempRow);
            currentRow++;
            currentCol = 0;
        }
    }
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
