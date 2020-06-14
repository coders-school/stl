#pragma once

#include <array>
#include <vector>

namespace
{
constexpr size_t width = 32; // 240;

constexpr size_t height = 32; // 160;

using VectorPair = std::vector<std::pair<uint8_t, uint8_t> >;

using ArrayArray = std::array<std::array<uint8_t, height>, width>;
}

VectorPair compressGrayscale(const ArrayArray& data);

ArrayArray decompressGrayscale(const VectorPair& data);

void printMap(const ArrayArray& data);
