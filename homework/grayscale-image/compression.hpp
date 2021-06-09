#pragma once
#include <array>
#include <vector>
#include <algorithm>
#include <iterator>
#include <utility>
#include <cstdint>
#include <cstddef>

constexpr size_t width = 32;
constexpr size_t height = 32;

using compressedGrayscaleImage = std::vector<std::pair<uint8_t, uint8_t>>;
using grayscaleImage = std::array<std::array<uint8_t, width>, height>;

compressedGrayscaleImage compressGrayscale(grayscaleImage);
grayscaleImage decompressGrayscale(compressedGrayscaleImage);
