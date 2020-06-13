#include "compression.hpp"

CompressedBitmap compressGrayscale(const Bitmap& bitmap) {
    
    CompressedBitmap compressed;
    uint8_t color;
    uint8_t count;

    for (size_t i = 0; i < height; i++) {

        color = bitmap[i][0];
        count = 1;

        for (size_t j = 1; j < width; j++) {
            if (color == bitmap[i][j]) {
                count++;
            } else {
                compressed.emplace_back(std::make_pair(color, count));
                color = bitmap[i][j];
                count = 1;
            }
        }
        compressed.emplace_back(std::make_pair(color, count));
    }

    return compressed;
}

Bitmap decompressGrayscale(const CompressedBitmap& compressed) {
    
    Bitmap bitmap;
    size_t i{0};
    size_t j{0};

    for (const auto & pair : compressed) {
        for (size_t k = j; k < (j + pair.second); k++) {
            bitmap[i][k] = pair.first;
        }
        j += pair.second;
        if (j == (width - 1)) {
            i++;
        }
    }
    
    return bitmap;
}
