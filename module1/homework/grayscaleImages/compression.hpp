#pragma once

#include <iostream>
#include <vector>
#include <array>

constexpr size_t width = 32;
constexpr size_t height = 32;
using bitmap_array = std::array<std::array<uint8_t, width>, height>;
using compressed_vec = std::vector<std::pair<uint8_t, uint8_t>>;

compressed_vec compressGrayscale(bitmap_array const bitmap);
bitmap_array decompressGrayscale(const compressed_vec comp_vec);
void printMap(bitmap_array input_map);