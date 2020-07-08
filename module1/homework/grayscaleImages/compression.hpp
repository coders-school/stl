#pragma once

#include <array>
#include <vector>

constexpr size_t width = 32;
constexpr size_t height = 32;

using bitMapType = std::array<std::array<uint8_t, width>, height>;
using uint8_tPairVector = std::vector<std::pair<uint8_t, uint8_t>>;

uint8_tPairVector compressGrayscale(bitMapType&);
bitMapType decompressGrayscale(uint8_tPairVector&);
void printMap(bitMapType&);