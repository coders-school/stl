#pragma once

#include <array>
#include <cstdint>
#include <utility>
#include <vector>

constexpr size_t width = 32;
constexpr size_t height = 32;

using SqueezedMap = std::vector<std::pair<uint8_t, uint8_t>>;
using DiffusedMap = std::array<std::array<uint8_t, width>, height>;

SqueezedMap compressGrayscale(DiffusedMap& getGray);
DiffusedMap decompressGrayscale(SqueezedMap Compressed);
void printMap(DiffusedMap& getMap);
