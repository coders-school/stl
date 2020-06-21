#include "compression.hpp"

#include <algorithm>

CompressedBitmap compressGrayscale(const Bitmap& bitmap) {
    CompressedBitmap compressed;

    compressed.reserve(width * height);
    std::for_each(bitmap.begin(), bitmap.end(), [&compressed](const auto& row) {
        uint8_t color = row.front();
        auto pixelIt = row.begin();
        while (pixelIt != row.end()) {     
            auto count = std::count_if(pixelIt, row.end(), [&color](auto pixel){ 
                return pixel == color;
            });
            compressed.push_back({color, count});
            std::advance(pixelIt, count);            
            color = *pixelIt;
        }
    });
    compressed.shrink_to_fit();

    return compressed;
}

Bitmap decompressGrayscale(const CompressedBitmap& compressed) {
    Bitmap bitmap;

    auto pixelIt = bitmap.front().begin();

    std::for_each(compressed.begin(), compressed.end(), [pixelIt](const auto& pair) mutable {
        pixelIt = std::fill_n(pixelIt, pair.second, pair.first); 
    });

    return bitmap;
}
