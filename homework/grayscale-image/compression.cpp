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

    //     std::transform(row.begin(), row.end(), std::back_inserter(compressed), [&](auto number) -> int {
    //         auto fountIt = std::adjacent_find(it, row.end(), std::not_equal_to<int>{});
    //         if (fountIt != row.end()) {
    //             fountIt++;
    //         }
    //         compressed.emplace_back(*it, std::distance(it, fountIt));
    //         it = fountIt;
    //     });
    // });
    // for (const auto& row : bitmap) {
    //     for (auto it = row.begin(); it != row.end(); ) {
    //         auto fountIt = std::adjacent_find(it, row.end(), std::not_equal_to<int>{});
    //         if (fountIt != row.end()) {
    //             fountIt++;
    //         }
    //         compressed.emplace_back(*it, std::distance(it, fountIt));
    //         it = fountIt;
    //     }
    // }
    return compressed;
}

grayscaleImage decompressGrayscale(const compressedGrayscaleImage& compressed) {
    grayscaleImage decompressed{};
    auto it = decompressed.front().begin();
    auto itEnd = decompressed.back().end();
    std::generate (it, itEnd, [i = 0, j = 0, compressed] () mutable{
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
