#include "compression.hpp"

compressedGrayscaleImage compressGrayscale(const grayscaleImage& bitmap) {
    compressedGrayscaleImage compressed;
    compressed.reserve(width * height);
    std::all_of(bitmap.begin(), bitmap.end(), [&compressed](auto row) {
        for (auto it = row.begin(); it != row.end(); ) {
            auto fountIt = std::adjacent_find(it, row.end(), std::not_equal_to<int>{});
            if (fountIt != row.end()) {
                fountIt++;
            }
            compressed.emplace_back(*it, std::distance(it, fountIt));
            it = fountIt;
        }
        return true;
    });
    return compressed;
}

grayscaleImage decompressGrayscale(const compressedGrayscaleImage& compressed) {
    grayscaleImage decompressed{};
    auto it = decompressed.front().begin();
    std::all_of(compressed.begin(), compressed.end(), [it](const auto& pair) mutable {
        it = std::fill_n(it, pair.second, pair.first);
        return true;
    });
    return decompressed;
}
