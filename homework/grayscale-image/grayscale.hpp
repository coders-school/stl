#pragma once
#include <iostream>
#include <algorithm>
#include <array>
#include <utility>
#include <vector>

constexpr size_t width = 32;
constexpr size_t height = 32;

using Bitmap = std::array<std::array<uint8_t, width>, height>;
using CompressedBitmap = std::vector<std::pair<uint8_t, uint8_t>>;

CompressedBitmap compressGrayscale(const Bitmap&);

Bitmap decompressGrayscale(const CompressedBitmap&);
 
void printMap(const Bitmap&);


