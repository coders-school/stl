#pragma once
#include <algorithm>
#include <array>
#include <pair>
#include <vector>

constexpr size_t width = 32;
constexpr size_t height = 32;

using Bitmap = std::array<uint8_t, width>, height>;
using CompressedBitmap = std::vector<std::pair<uint8_t, uint8_t>;

CompressedBitmap compressGrayscale(Bitmap);

Bitmap decompressGrayscale(CompressedBitmap);
 
void printMap(Bitmap);


