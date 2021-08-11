#pragma once
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>
#include <array>

inline constexpr size_t width{32};
inline constexpr size_t height{32};

using CompressedBitmap = std::vector<std::pair<uint8_t, uint8_t>>;
using Bitmap = std::array<std::array<uint8_t, width>, height>;

Bitmap decompressGrayscale(const CompressedBitmap&);

CompressedBitmap compressGrayscale(const Bitmap&);
char grayscaleToAscii(uint8_t grayscale);
void printMap(const Bitmap&);