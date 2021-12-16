#pragma once

#include <array>
#include <vector>
#include <cstdint>

constexpr size_t width{ 32 };
constexpr size_t height{ 32 };
constexpr uint8_t printable_ascii_min{ 32 };
constexpr uint8_t printable_ascii_max{ 126 };

using compressedBitmap = std::vector<std::pair<uint8_t, uint8_t>>;
using bitmap = std::array<std::array<uint8_t, width>, height>;

compressedBitmap compressGrayscale(const bitmap& bitmap);
bitmap decompressGrayscale(const compressedBitmap& compressed);
void printMap(const bitmap& bitmap);