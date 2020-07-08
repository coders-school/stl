#pragma once

#include <array>
#include <cstdint>
#include <vector>

constexpr const size_t width = 32;
constexpr const size_t height = 32;

using compressedImage = std::vector<std::pair<uint8_t, uint8_t>>;
using decompressedImage = std::array<std::array<uint8_t, width>, height>;
using decompressedLine = std::array<uint8_t, width>;

compressedImage compressGrayscale(decompressedImage& a);
compressedImage compressSingleLine(decompressedLine& line);
decompressedImage decompressGrayscale(compressedImage& v);
