#pragma once
#include <array>
#include <vector>
#include <cctype>

constexpr size_t width = 32;
constexpr size_t height = 32;

using bitmap = std::array<std::array<uint8_t, width>, height>;
using compressed_bitmap = std::vector<std::pair<uint8_t, uint8_t>>;

compressed_bitmap compressGrayscale(bitmap& bitmap);
bitmap decompressGrayscale(const compressed_bitmap& map);
void printCompressedVector(const compressed_bitmap& map);
void printMap(const bitmap& map);
