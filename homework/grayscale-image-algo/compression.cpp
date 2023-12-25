#include "compression.hpp"

#include <algorithm>

std::vector<std::pair<uint8_t, uint8_t>>
compressGrayscale(const std::array<std::array<uint8_t, width>, height>& image) {
    std::vector<std::pair<uint8_t, uint8_t>> result;
    std::for_each(image.cbegin(), image.cend(), [&result](const auto& elem1){
        uint8_t count = 1;
        uint8_t prevColor = 0;
        std::for_each(elem1.cbegin(),
                      elem1.cend(),
                      [&result, &count, &prevColor, &elem1, j = 0](const auto& elem2) mutable {
            if (j == 0) {
                prevColor = elem1[j];
            } else {
                if (prevColor != elem1[j]) {
                    result.push_back(std::make_pair(prevColor, count));
                    count = 1;
                    prevColor = elem1[j];
                } else {
                    count++;
                }
            }
            j++;
        });
        result.push_back(std::make_pair(prevColor, count));
    });

    // for (size_t i = 0; i < height; i++) {
    //     uint8_t count = 1;
    //     uint8_t prevColor = 0;
    //     for (size_t j = 0; j < width; j++) {
    //         if (j == 0) {
    //             prevColor = image[i][j];
    //         } else {
    //             if (prevColor != image[i][j]) {
    //                 result.push_back(std::make_pair(prevColor, count));
    //                 count = 1;
    //                 prevColor = image[i][j];
    //             } else {
    //                 count++;
    //             }
    //         }
    //     }
    //     result.push_back(std::make_pair(prevColor, count));
    // }
    return result;
}

std::array<std::array<uint8_t, width>, height>
decompressGrayscale(const std::vector<std::pair<uint8_t, uint8_t>>& compressed) {
    std::array<std::array<uint8_t, width>, height> result;
    uint8_t lineLength = 0;
    size_t i = 0;
    for (const auto& elem : compressed) {
        for (size_t j = lineLength; j < lineLength + elem.second; j++) {
            result[i][j] = elem.first;
        }
        lineLength += elem.second;
        if (lineLength == width) {
            i++;
            lineLength = 0;
        }
    }
    return result;
}
