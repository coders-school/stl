#pragma once

#include <array>
#include <utility>
#include <vector>

namespace {
typedef uint8_t Pixel;
typedef uint8_t WidthType;
typedef uint8_t HeightType;
constexpr WidthType width = 240;
constexpr HeightType height = 160;
typedef std::array<std::array<Pixel, width>, height> PGMBitMap;
typedef std::vector<std::pair<Pixel, WidthType>> CompressedPGMBitMap;
}  // namespace

CompressedPGMBitMap compressGrayscale(const PGMBitMap&);
PGMBitMap decompressGrayscale(const CompressedPGMBitMap&);

void printMap(const PGMBitMap&);
