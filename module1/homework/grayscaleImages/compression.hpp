#pragma once

#include <array>
#include <vector>

constexpr unsigned int height = 160;
constexpr unsigned int width = 240;

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height>);  //TODO: Name for the parameter

std::array<std::array<uint8_t, width>, height> decompressGrayscale(const std::vector<std::pair<uint8_t, uint8_t>>& compressedMap);
