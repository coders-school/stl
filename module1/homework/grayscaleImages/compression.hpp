#pragma once

#include <array>
#include <vector>

constexpr size_t width = 32;
constexpr size_t height = 32;

std::array<std::array<int, width>, height> decompressGrayscale(const std::vector<std::pair<int, int>>&);