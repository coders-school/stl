#ifndef COMPRESSION_HPP
#define COMPRESSION_HPP

#include <cstdint>
#include <vector>
#include <utility>
#include <array>
#include <cstddef>

constexpr size_t width = 32;
constexpr size_t height = 32;

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, 32>, 32>& img);
std::array<std::array<uint8_t, 32>, 32> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>>& compress);

#endif
