#pragma once

#include <array>
#include <vector>

constexpr size_t width = 32;
constexpr size_t height = 32;

using bitmap = std::array<std::array<uint8_t, width>, height>;
using compressed_bitmap = std::vector<std::pair<uint8_t, uint8_t>>;

compressed_bitmap compressGrayscale(const bitmap&);
bitmap decompressGrayscale(const compressed_bitmap&);
void printMap(const bitmap&);
