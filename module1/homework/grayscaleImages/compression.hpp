#pragma once

#include <array>
#include <vector>

constexpr size_t width = 32;
constexpr size_t height = 32;

using vector_of_pairs = std::vector<std::pair<uint8_t, uint8_t>>;
using array_of_arrays = std::array<std::array<uint8_t, width>, height>;

vector_of_pairs compressGrayscale(const array_of_arrays&);
array_of_arrays decompressGrayscale(const vector_of_pairs&);
void printMap(const array_of_arrays&);
