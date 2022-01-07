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
    Image result {};

    auto it = compressed_bitmap.begin();

    for (auto& row : result) {
        std::size_t col { 0 };
        while (col < row.size()) {
            auto color = it->first;
            auto count = it->second;
            for (auto i = count; i > 0; --i) {
                row[col] = color;
                ++col;
            }
            ++it;
        }
        // for (std::size_t col = 0; col < row.size(); ) {
        //     for(std::size_t repeat = *it->second ; repeat > 0 ; --repeat ){
        //       row[col] = *it->first;
        //     }
        // }
    }

    // for (auto row : result) {
    //     for (auto pixel : row) {
    //         pixel = 0;
    //     }
    // }

    // std::size_t row { 0 };
    // std::size_t column { 0 };
    // for (const auto& pair : compressed_bitmap) {
    //     for (std::size_t i = 0; i < pair.second; ++i) {
    //         result[row][column] = pair.first;
    //         ++column;
    //         if (column = width) {
    //             column = 0;
    //             ++row;
    //         }
    //     }
    // }

    // std::size_t el_count { 0 };
    // // std::size_t column { 0 }; REMOVE
    // for (const auto& pair : compressed_bitmap) {
    //     for (std::size_t i = 0; i < pair.second, el_count < height * width; ++i, ++el_count) {
    //         result[el_count / width][el_count % width] = pair.first;
    //         // ++el_count; REMOVE
    //     }
    // }

    return result;
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

// // Helper function for decompressGrayscale. TODO:
// // Decompresses a single row from the compressed bitmap
// BitmapRow decompressRow(const CompressedImage& compressed_bitmap, BitmapRow::iterator& it)
// {}