#include "compression.hpp"

#include <iostream>

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
    Image result;
    if (compressed_bitmap.empty()) {
        return result;
    }
    auto it = compressed_bitmap.begin();
    for (auto& row : result) {
        decompressRow(row, it);
    }

    return result;
}

// Helper function for compressGrayscale. Parses single row of a bitmap
// and inserts compressed data into passed compressed_bitmap
void compressRow(const BitmapRow& row, CompressedImage& compressed_bitmap)
{
    auto it = row.begin();
    while (it != row.end()) {
        auto pixel_color = *it;
        auto repeat_count { 1 };
        // check next element for same color occurences
        while (++it != row.end() && *it == pixel_color) {
            ++repeat_count;
        }
        compressed_bitmap.emplace_back(pixel_color, repeat_count);
    }
}

// Helper function for decompressGrayscale.
// Decompresses a single row from the compressed bitmap.
// Takes target row for the decompressed data and iterator pointing where to start
// reading from compressed image
void decompressRow(BitmapRow& row, CompressedImage::const_iterator& iterator)
{
    std::size_t column { 0 };
    while (column < row.size()) {
        auto color = iterator->first;
        auto repeat = iterator->second;
        for (auto i = repeat; i > 0; --i) {
            row[column] = color;
            ++column;
        }
        ++iterator;
    }
}

// prints an uncompressed bitmap
void printMap(const Image& bitmap)
{
    for (const auto& row : bitmap) {
        for (auto pixel : row) {
            // std::cout << std::noskipws << pixel;
            std::cout.put(pixel);
        }
        std::cout << std::endl;
    }
}