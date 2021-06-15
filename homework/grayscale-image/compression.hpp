#pragma once

#include <array>
#include <utility>
#include <vector>

#include <cctype>
#include <iostream>

constexpr size_t width = 32;
constexpr size_t height = 32;

using pixelType = uint8_t;
using imageLine = std::array<pixelType, width>;
using image = std::array<imageLine, height>;
using compressPair = std::pair<pixelType, uint8_t>;
using compressedImage = std::vector<compressPair>;

[[nodiscard]] compressedImage compressGrayscale(const image& image);

[[nodiscard]] image decompressGrayscale(const compressedImage& pack);

void printMap(const image& map);

void printCompresedMap(const compressedImage& compressed);
