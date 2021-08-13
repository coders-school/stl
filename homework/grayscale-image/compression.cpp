#include "compression.hpp"
#include <algorithm>

Bitmap decompressGrayscale(const CompressedBitmap& compressed) {
    Bitmap output{};
    std::for_each(compressed.cbegin(), compressed.cend(), [rowIt = output.begin(), count = 0](const auto& pair) mutable {
            std::fill_n(rowIt->begin() + count, pair.second, pair.first);
            count += pair.second;
            if(count == width)
            {
                ++rowIt;
                count = 0;
            }
    });
    return output;
}

CompressedBitmap compressGrayscale(const Bitmap& decompressed) {
    CompressedBitmap output{};
    output.reserve(width * height);

    std::for_each(decompressed.cbegin(), decompressed.cend(), [&output](const auto& row) {
        auto pairCount = std::count_if(row.cbegin(), row.cend(), [currIt = row.cbegin(), startIt = row.cbegin()](const auto value) mutable {
                if(value != *startIt) {
                    startIt = currIt;
                    ++currIt;
                    return true;
                }
                ++currIt;
                return false;
        });
        ++pairCount; // adjust for the last value
        std::generate_n(std::back_inserter(output), pairCount, [rowIt = row.cbegin(), &row]()  mutable {
            auto valCount = std::distance(rowIt, std::find_if_not(rowIt, row.cend(), [rowIt](const auto val) { return val == *rowIt; }));
            auto value = *rowIt;
            std::advance(rowIt, valCount);
            return std::pair<uint8_t, uint8_t>{ value, valCount };
            
        });
    });

    output.shrink_to_fit();
    return output;
}
