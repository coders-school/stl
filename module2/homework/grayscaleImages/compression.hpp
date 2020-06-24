#pragma once

#include <array>
#include <vector>

constexpr uint32_t height = 32;
constexpr uint32_t width = 32;

void printMap (const std::array<std::array<uint8_t, width>, height> &bitmap);
std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale (const std::array<std::array<uint8_t, width>, height> &bitmap);

std::array<std::array<uint8_t, width>, height> decompressGrayscale(const std::vector<std::pair<uint8_t, uint8_t>> &compressed);
