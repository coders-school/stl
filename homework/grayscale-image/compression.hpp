#pragma once

#include <array>
#include <utility>
#include <vector>

#include <cctype>
#include <iostream>

constexpr size_t width = 32;
constexpr size_t height = 32;

using PixelType = uint8_t;
using ImageLine = std::array<PixelType, width>;
using Image = std::array<ImageLine, height>;
using CompressPair = std::pair<PixelType, uint8_t>;
using CompressedImage = std::vector<CompressPair>;

[[nodiscard]] CompressedImage compressGrayscale(const Image& image);

[[nodiscard]] Image decompressGrayscale(const CompressedImage& pack);

void printMap(const Image& map);

void printCompresedMap(const CompressedImage& compressed);
