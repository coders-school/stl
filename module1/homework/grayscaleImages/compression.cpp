#include "compression.hpp"

CompressedBitmap compressGrayscale(const Bitmap& bitmap) {
    CompressedBitmap compressed;
    compressed.reserve(width * height);
    uint8_t count;
    uint8_t color_code;

    for (const auto& row : bitmap) {
        color_code = row.front();
        count = 1;
        for (auto element = row.begin(); element != row.end(); ++element) {
            auto next = std::next(element);
            if (color_code != *next || next == row.end()) {
                compressed.emplace_back(std::make_pair(color_code, count));
                color_code = *next;
                count = 1;
            } else {
                ++count;
            }
        }
    }
    compressed.shrink_to_fit();
    return compressed;
}

Bitmap decompressGrayscale(const CompressedBitmap& compressed) {
    Bitmap decompressed;
    auto it = compressed.begin();
    size_t i = 0;
    for (size_t row = 0; row < height; ++row) {
        for (size_t column = 0; column < width;) {
            while (i++ < it->second) {
                decompressed[row][column] = it->first;
                column++;
            }
            i = 0;
            ++it;
        }
    }
    return decompressed;
}
