#pragma once

#include <array>
#include <utility>
#include <vector>

using Pixel = uint8_t;
using WidthType = uint8_t;
using HeightType = uint8_t;
constexpr WidthType width = 32;
constexpr HeightType height = 32;
using PGMBitMap = std::array<std::array<Pixel, width>, height>;
using CompressedPGMBitMap = std::vector<std::pair<Pixel, WidthType>>;

CompressedPGMBitMap compressGrayscale(const PGMBitMap& img);
PGMBitMap decompressGrayscale(const CompressedPGMBitMap& compressedImg);
void printMap(const PGMBitMap& img);
