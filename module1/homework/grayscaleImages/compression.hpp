#pragma once

#include <array>
#include <vector>

constexpr size_t width = 32;
constexpr size_t height = 32;

using CompressedImage = std::vector<std::pair<uint8_t, uint8_t>>;
using UncompressedImage = std::array<std::array<uint8_t, height>, width>;

CompressedImage compressGrayscale(const UncompressedImage& uncompressed);

UncompressedImage decompressGrayscale(const CompressedImage& compressed);

void printMap(const UncompressedImage& bitmap);
