#pragma once

#include <array>
#include <vector>

constexpr size_t width = 32;
constexpr size_t height = 32;

using RawMap = std::array<std::array<uint8_t, height>, width>;
using Compressed = std::vector<std::pair<uint8_t, uint8_t>>;

char convert2Printable(uint8_t input);
void printMap(const RawMap& input);
void printVectorOfPairs(const Compressed& input);
Compressed compressGrayscale(const RawMap& input);
RawMap decompressGrayscale(const Compressed& input);
