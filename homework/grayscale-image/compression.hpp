#pragma once
#include <array>
#include <vector>
#include <utility>
#include <stdint.h>
constexpr size_t width = 32;
constexpr size_t height = 32;

using compressedImage = std::vector<std::pair<uint8_t, uint8_t>>;
using image = std::array<std::array<uint8_t, width>, height>;

compressedImage compressGrayscale(const image&);
image decompressGrayscale(const compressedImage&);