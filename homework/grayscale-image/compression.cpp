#include <cstdint>
#include <iostream>
#include <utility>

#include "compression.hpp"

CompressedImage compressGrayscale(const Image& decompressedImage)
{
    CompressedImage compressed;
    for (const auto& row : decompressedImage) {
        uint8_t value = row[0], counter = 1;
        for (size_t i = 1; i < row.size(); ++i) {
            counter++;
            if (i == (row.size() - 1)) {
                compressed.push_back({ value, counter });
            } else if (value != row[i]) {
                compressed.push_back({ value, --counter });
                value = row[i];
                counter = 1;
            }
        }
    }
    return compressed;
}

Image decompressGrayscale(const CompressedImage& compressedImage)
{
    Image decompressedImage;
    size_t indexForRow = 0;
    size_t indexForColumn = 0;
    for (const auto& el : compressedImage) {
        for (size_t i = 0; i < el.second; ++i) {
            if (indexForColumn < width) {
                decompressedImage[indexForRow][indexForColumn++] = el.first;
            } else {
                indexForColumn = 0;
                decompressedImage[++indexForRow][indexForColumn++] = el.first;
            }
        }
    }
    return decompressedImage;
}
