#include "compression.hpp"

#include <algorithm>
#include <vector>

compressedGrayscaleImage compressGrayscale(const grayscaleImage& bitmap) {
    compressedGrayscaleImage compressed;
    compressed.reserve(width * height);
    std::for_each(bitmap.cbegin(), bitmap.cend(), [&compressed](const auto& row){
        for (auto it = row.begin(); it != row.end();) {
            auto found = std::adjacent_find(it, row.end(), std::not_equal_to<int>{});
            if (found != row.end()) {
                found++;
            }
            compressed.emplace_back(*it, std::distance(it, found));
            it = found;
        }
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
