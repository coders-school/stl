#pragma once
#include <array>
#include <vector>

constexpr size_t width = 32;
constexpr size_t height = 32;
constexpr size_t size = width * height;

using compressedType = std::vector<std::pair<uint8_t, uint8_t>>;
using bitmapType = std::array<std::array<uint8_t, width>, height>;

compressedType compressGrayscale(bitmapType&);
bitmapType decompressGrayscale(compressedType&);