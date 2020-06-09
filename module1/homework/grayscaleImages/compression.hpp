#pragma once
#include <algorithm>
#include <array>
#include <utility>
#include <vector>

constexpr size_t width = 240;
constexpr size_t height = 160;

using CompressedBitmap = std::vector<std::pair<uint8_t, uint8_t>>;
using Line =  std::array<uint8_t, width>;
using Bitmap =  std::array<std::array<uint8_t, width>, height>;

CompressedBitmap compressGrayscale(Bitmap bitmap);
Bitmap decompressGrayscale(CompressedBitmap compressedBitmap);
CompressedBitmap compressLine(std::array<uint8_t, 10>);
void printMap(Bitmap);


