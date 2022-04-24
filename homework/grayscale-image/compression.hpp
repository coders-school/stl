#pragma once

#include <array>
#include <cstdint>
#include <utility>
#include <vector>
#include <algorithm>
constexpr size_t width = 32;
constexpr size_t height = 32;

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height> Gray);

std::array<std::array<uint8_t, width>, height> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>> Decompres);
