#pragma once

#include <array>
#include <vector>
#include <algorithm>

constexpr size_t width = 32;
constexpr size_t height = 32;

using bitMap = std::array<std::array<uint8_t, width>, height>;
using comprBitMap = std::vector<std::pair<uint8_t, uint8_t>>;

comprBitMap compressGrayscale(const bitMap& arr);
bitMap decompressGrayscale(comprBitMap);