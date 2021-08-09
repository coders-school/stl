#include "compression.hpp"

compressedGrayscaleImage compressGrayscale(const grayscaleImage& bitmap) {
    compressedGrayscaleImage compressed;
    compressed.reserve(width * height);
    for (const auto& row : bitmap) {
        for (auto it = row.begin(); it != row.end(); ) {
            auto fountIt = std::adjacent_find(it, row.end(), std::not_equal_to<int>{});
            if (fountIt != row.end()) {
                fountIt++;
            }
            compressed.emplace_back(*it, std::distance(it, fountIt));
            it = fountIt;
        }
    }
    return compressed;
}

grayscaleImage decompressGrayscale(const compressedGrayscaleImage& compressed) {
    grayscaleImage decompressed{};
    auto it = decompressed[0].begin();
    std::for_each(compressed.begin(), compressed.end(), [it](const auto& pair) mutable {
        it = std::fill_n(it, pair.second, pair.first);
    });
    return decompressed;
}
