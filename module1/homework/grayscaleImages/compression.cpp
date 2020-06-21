#include "compression.hpp"

#include <algorithm>

CompressedBitmap compressGrayscale(const Bitmap& bitmap) {
    CompressedBitmap compressed;
    compressed.reserve(width * height);

    for (const auto& row : bitmap) {
        for (auto element = row.begin(); element != row.end();) {
            auto it = std::adjacent_find(element, row.end(), [](uint8_t lhs, uint8_t rhs) { return lhs != rhs; });
            if (it != row.end()) {
                it++;
            }
            compressed.emplace_back(*element, std::distance(element, it));
            element = it;
        }
    }
    compressed.shrink_to_fit();
    return compressed;
}

Bitmap decompressGrayscale(const CompressedBitmap& compressed) {
    Bitmap decompressed{};
    auto it = decompressed.front().begin();
    std::for_each(compressed.begin(), compressed.end(), [it](const auto& pair) mutable {
        it = std::fill_n(it, pair.second, pair.first);
    });
    return decompressed;
}
