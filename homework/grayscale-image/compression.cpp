#include "compression.hpp"

// compresses a bitmap into compressedImage format
CompressedImage compressGrayscale(const Image& bitmap)
{
    CompressedImage result;
    for (const auto& row : bitmap) {
        compressRow(row, result);
    }

    return result;
}

// decompresses a compressed image into a grayscale bitmap
Image decompressGrayscale(const CompressedImage& compressed_bitmap)
{
    // REMOVE after implementation
    return Image {};
}

// Helper function for compressGrayscale. Parses single row of a bitmap
// and inserts compressed data into passed compressed_bitmap
void compressRow(const BitmapRow& row, CompressedImage& compressed_bitmap)
{
    auto it = row.begin();
    while (it != row.end()) {
        uint8_t pixel_color = *it;
        uint8_t repeat_count { 1 };
        // check next element for same color occurences
        while (++it != row.end() && *it == pixel_color) {
            ++repeat_count;
        }
        compressed_bitmap.emplace_back(pixel_color, repeat_count);
    }
}
