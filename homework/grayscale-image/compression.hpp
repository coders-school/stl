#pragma once

#include <array>
#include <iterator>
#include <utility>
#include <vector>

constexpr size_t width = 32;
constexpr size_t height = 32;

using compressedGrayscaleImage = std::vector<std::pair<uint8_t, uint8_t>>;
using grayscaleImage = std::array<std::array<uint8_t, width>, height>;

compressedGrayscaleImage compressGrayscale(const grayscaleImage&);
grayscaleImage decompressGrayscale(const compressedGrayscaleImage&);