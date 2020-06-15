#pragma once

#include <array>
#include <vector>

constexpr size_t width = 32;
constexpr size_t height = 32;
constexpr unsigned char printable_limit = ' ';

using Image = std::array<std::array<uint8_t, width>, height>;
using compressedImage = std::vector<std::pair<uint8_t, uint8_t>>;

compressedImage compressGrayscale(const Image&);
Image decompressGrayscale(const compressedImage&);
void printMap(const Image&);

