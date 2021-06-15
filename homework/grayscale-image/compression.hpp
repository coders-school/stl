#pragma once
#include <cstddef>
#include <array>
#include <vector>

constexpr size_t width = 32;
constexpr size_t height = 32;

using image_t = std::array<std::array<uint8_t, width>, height>;
using image_compressed_t = std::vector<std::pair<uint8_t, uint8_t>>;

image_compressed_t compressGrayscale(image_t& image);
image_t decompressGrayscale(image_compressed_t& imageCompressed);