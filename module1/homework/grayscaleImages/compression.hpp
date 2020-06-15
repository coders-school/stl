#pragma once
#include <array>
#include <vector>

constexpr size_t width = 32;
constexpr size_t height = 32;

using twoDimensionalArray = std::array<std::array<uint8_t, width>, height>;
using pairVector = std::vector<std::pair<uint8_t, uint8_t>>;

pairVector compressGrayscale(const twoDimensionalArray&);
twoDimensionalArray decompressGrayscale(const pairVector&);
void printMap(const twoDimensionalArray&);
