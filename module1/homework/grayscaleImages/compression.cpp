#include "compression.hpp"

compressed_bitmap compressGrayscale(const bitmap& image) {
    compressed_bitmap compressedImage{};
    compressedImage.reserve(height * width);

    std::pair<uint8_t, uint8_t> currentPair;
    uint8_t greyscale;

    for (const auto& el : image) {
        currentPair = std::make_pair(el.front(), 1);

        for (size_t j = 1; j < width; ++j) {
            greyscale = el[j];
            if (greyscale == currentPair.first) {
                ++currentPair.second;
                if (width != j + 1) {
                    continue;
                }
            }
            compressedImage.push_back(currentPair);
            currentPair = std::make_pair(greyscale, 1);
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
