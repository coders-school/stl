#pragma once

#include <array>
#include <utility>
#include <vector>


constexpr size_t width = 32;
constexpr size_t height = 32;

using compressedBitmap = std::vector<std::pair<uint8_t, uint8_t>>;
using image = std::array<std::array<uint8_t, width>, height>;

compressedBitmap compressGrayscale(const image& img);

image decompressGrayscale(const compressedBitmap& bmp);

void printMap(const image& img);
