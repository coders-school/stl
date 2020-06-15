#pragma once

#include <algorithm>
#include <array>
#include <vector>
#include <iterator>

constexpr size_t height = 32;
constexpr size_t width = 32;


using Image = std::array<std::array<uint8_t, width>, height>;

using Compressed = std::vector<std::pair<uint8_t, uint8_t>>;

Compressed compressGrayscale(const Image& compress);

Image decompressGrayscale(const Compressed& compressedMap);

void printMap(const Image& mapToPrint);
