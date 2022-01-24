#pragma once

#include <array>
#include <cstddef>
#include <cstdint>
#include <vector>

constexpr size_t width = 32;
constexpr size_t height = 32;

using Image = std::array<std::array<uint8_t, width>, height>;
using CompressedImage = std::vector<std::pair<uint8_t, uint8_t>>;
using BitmapRow = std::array<uint8_t, width>;

// compresses a grayscale bitmap into compressedImage format
CompressedImage compressGrayscale(const Image& bitmap);

// decompresses a compressed image into a grayscale bitmap
Image decompressGrayscale(const CompressedImage& compressed_bitmap);

// prints an uncompressed bitmap
void printMap(const Image& bitmap);