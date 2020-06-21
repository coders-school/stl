#include "compression.hpp"

#include <algorithm>
#include <iostream>
#include <string>

CompressedImage compressGrayscale(const UncompressedImage& uncompressed) {
    CompressedImage compressed;
    compressed.reserve(height * width);

    std::for_each(uncompressed.begin(), uncompressed.end(), [&](auto row) {
        auto groupBegin = row.begin();
        auto nextGroupBegin = row.end();

        do {
            uint8_t firstPixelInGroup = *groupBegin;
            nextGroupBegin =
                std::find_if_not(groupBegin,
                                 row.end(),
                                 [&firstPixelInGroup](auto currentPixel) {
                                     return currentPixel == firstPixelInGroup;
                                 });

            auto groupSize = std::distance(groupBegin, nextGroupBegin);
            compressed.push_back(std::make_pair(*groupBegin, groupSize));
            groupBegin = nextGroupBegin;
        } while (nextGroupBegin != row.end());
    });

    compressed.shrink_to_fit();
    return compressed;
}

UncompressedImage decompressGrayscale(const CompressedImage& compressed) {
    UncompressedImage uncompressed;
    auto pixelIterator = uncompressed[0].begin();

    std::for_each(compressed.begin(), compressed.end(), [&](const auto& pixelGroup) {
        pixelIterator = std::fill_n(pixelIterator, pixelGroup.second, pixelGroup.first);
    });

    return uncompressed;
}

void printMap(UncompressedImage& bitmap) {
    const std::string palette = R"( .:-=+*#%@)";
    int level;
    const double normalizingFactor = palette.size() / 256.0;
    std::cout << "\n";

    for (auto& row : bitmap) {
        for (auto pixel : row) {
            level = pixel * normalizingFactor;
            std::cout << palette[level];
        }
        std::cout << "\n";
    }
}
