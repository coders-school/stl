#pragma once

#include <array>
#include <utility>
#include <vector>

constexpr size_t width = 32;
constexpr size_t height = 32;

using rawMap = std::array<std::array<uint8_t, height>, width>;
using compressed = std::vector<std::pair<uint8_t, uint8_t>>;

void printMap(const rawMap& input);
void printVectorOfPairs(const compressed& input);
compressed compressGrayscale(const rawMap& input);
rawMap decompressGrayscale(const compressed& input);
