#pragma once

#include <array>
#include <vector>

constexpr size_t width = 32;
constexpr size_t height = 32;

using bitmapArr = std::array<std::array<uint8_t, width>, height>;
using grayScaleVec = std::vector<std::pair<uint8_t, uint8_t>>;

void printMap(const bitmapArr&);
grayScaleVec compressGrayscale(const bitmapArr&);
bitmapArr decompressGrayscale(const grayScaleVec&);
