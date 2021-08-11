#include "compression.hpp"

#include <algorithm>

compressedGrayscaleImage compressGrayscale(const grayscaleImage& bitmap) {
    compressedGrayscaleImage compressed;
    compressed.reserve(width * height);
    std::all_of(bitmap.begin(), bitmap.end(), [&compressed](auto row) {
        auto it = row.begin();
        std::all_of(row.begin(), row.end(), [&](const auto& el) {
            if (it != row.end()) {
                uint8_t color = *it;
                auto foundIt = std::find_if_not(it, row.end(), [color](uint8_t other) {
                    return color == other;
                });
                compressed.emplace_back(color, std::distance(it, foundIt));
                it = foundIt;
            }
            return true;
        });
        return true;
    });
    compressed.shrink_to_fit();
    return compressed;
}

grayscaleImage decompressGrayscale(const compressedGrayscaleImage& compressed) {
    grayscaleImage decompressed{};
    auto it = decompressed.front().begin();
    auto itEnd = decompressed.back().end();
    std::generate(it, itEnd, [i = std::size_t{0}, j = 0, compressed]() mutable {
        if (j < compressed[i].second) {
            ++j;
        } else {
            ++i;
            j = 1;
        }
        return (compressed[i].first);
    });
    return decompressed;
}
