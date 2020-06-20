#include "compression.hpp"

CompressedBitmap compressGrayscale(const Bitmap& bitmap) {
    CompressedBitmap compressed;
    uint8_t color;
    uint8_t count;

    compressed.reserve(width * height);
    for (const auto& row : bitmap) {
        color = row.front();
        count = 1;
        for (auto pixelIt = row.begin(); pixelIt != row.end(); pixelIt++) {
            auto nextIt = std::next(pixelIt);
            if ((nextIt == row.end()) or (color != *nextIt)) {
                compressed.emplace_back(std::make_pair(color, count));
                if (nextIt != row.end()) {
                    color = *nextIt;
                    count = 1;
                }
            } else {
                count++;
            }
        }
    }
    compressed.shrink_to_fit();

    return compressed;
}

Bitmap decompressGrayscale(const CompressedBitmap& compressed) {
    Bitmap bitmap;
    auto pairIt = compressed.begin();
    size_t i{0};

    for (auto& row : bitmap) {
        for (auto pixelIt = row.begin(); pixelIt != row.end(); pixelIt++) {
            if (pairIt != compressed.end()) {
                *pixelIt = (*pairIt).first;
            } else {
                break;
            }
            i++;
            if (i >= (*pairIt).second) {
                i = 0;
                pairIt++;
            } 
        }
    }

    return bitmap;
}
