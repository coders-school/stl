#pragma once

#include <array>
#include <cstddef>
#include <cstdint>
#include <vector>

constexpr std::size_t width = 32;
constexpr std::size_t height = 32;

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, width>, height>& arr);

std::array<std::array<uint8_t, width>, height> decompressGrayscale(const std::vector<std::pair<uint8_t, uint8_t>>& bitmap);

void printMap(const std::array<std::array<uint8_t, width>, height>& map);
