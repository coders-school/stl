#pragma once
#include <array>
#include <vector>

constexpr size_t width = 32;
constexpr size_t height = 32;

using Compressed = std::vector<std::pair<uint8_t, uint8_t>>;
using Decompressed = std::array<std::array<uint8_t, width>, height>;


Compressed compressGrayscale(const Decompressed& input);

Decompressed decompressGrayscale(const Compressed& input);

void printMap(const Decompressed& map);

void printMap(const Compressed& map);
