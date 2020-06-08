#include "compression.hpp"

compressed_bitmap compressGrayscale(const bitmap& image) {
    compressed_bitmap compressedImage{};
    compressedImage.reserve(height * width);

    uint8_t currentGrayscale;
    uint8_t counter;
    uint8_t grayscale;

    for (size_t i = 0; i < height; ++i) {
        currentGrayscale = image[i][0];
        counter = 1;
        for (size_t j = 1; j < width; ++j) {
            grayscale = image[i][j];
            if (grayscale == currentGrayscale) {
                counter++;
            } else {
                compressedImage.push_back({currentGrayscale, counter});
                currentGrayscale = grayscale;
                counter = 1;
            }
        }
        compressedImage.push_back({currentGrayscale, counter});
    }
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
