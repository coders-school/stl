#pragma once
#include <array>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstdint>

std::vector<std::pair<std::uint8_t, std::uint8_t>> compressGrayscale(const std::array<std::array<std::uint8_t, 240>, 160>& image_array);
std::array<std::array<std::uint8_t, 240>, 160> decompressGrayscale(const std::vector<std::pair<std::uint8_t, std::uint8_t>>& image_vector);

constexpr size_t width = 32;
constexpr size_t height = 32;