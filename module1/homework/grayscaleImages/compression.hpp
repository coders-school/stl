#pragma once

#include <array>
#include <utility>
#include <vector>

#include <cstdint>

constexpr size_t width = 32;
constexpr size_t height = 32;

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height> getGray);
std::array<std::array<uint8_t, width>, height> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>> Compressed);
void printMap (const std::array<std::array<uint8_t, width>, height>& getMap);
