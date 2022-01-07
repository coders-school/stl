#pragma once

#include <array>
#include <vector>

constexpr size_t width = 240;
constexpr size_t height = 160;

using Image = std::array<std::array<uint8_t, width>, height>;
using CompressedImage = std::vector<std::pair<uint8_t, uint8_t>>;
using BitmapRow = std::array<uint8_t, width>;

// compresses a grayscale bitmap into compressedImage format
CompressedImage compressGrayscale(const Image& bitmap);

// decompresses a compressed image into a grayscale bitmap
Image decompressGrayscale(const CompressedImage& compressed_bitmap);

// Helper function for compressGrayscale. Parses single row of a bitmap
// and inserts compressed data into passed compressed_bitmap
void compressRow(const BitmapRow& row, CompressedImage& compressed_bitmap);

// Helper function for decompressGrayscale.
// Decompresses a single row from the compressed bitmap
// Takes TODO: REMOVE INU
BitmapRow decompressRow(const CompressedImage& compressed_bitmap, BitmapRow::iterator& it);