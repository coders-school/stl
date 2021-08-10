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
    auto begin = decompressed.front().begin();
    auto end = decompressed.back().end();
    std::generate (begin, end, [i = 0, j = 0, compressed] () mutable{
            if ( j < compressed[i].second ){
                ++j;
            } else {
                ++i;
                j = 1;
            }
            return (compressed[i].first);
    });
    return decompressed;
}
