#pragma once
#include <array>
#include <utility>  // for std::pair<>
#include <vector>

constexpr size_t height = 160;
constexpr size_t width = 240;

using Image = std::array<std::array<uint8_t, width>, height>;
using compressedImage =  std::vector<std::pair<uint8_t, uint8_t>>;

compressedImage compressGrayscale(const Image& imgToCompress);
Image decompressGrayscale(const compressedImage& imgToDecompress);
void printMap(const Image& bitmap);
