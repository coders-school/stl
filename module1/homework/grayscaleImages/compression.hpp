#pragma once

#include <array>
#include <vector>

constexpr size_t width = 32;
constexpr size_t height = 32;

using CompressedBitmap = std::vector<std::pair<uint8_t, uint8_t>>;
using Bitmap = std::array<std::array<uint8_t, width>, height>;

CompressedBitmap compressGrayscale(const Bitmap& bitmap);

Bitmap decompressGrayscale(const CompressedBitmap& compressed);

void printMap(const Bitmap& bitmap);
