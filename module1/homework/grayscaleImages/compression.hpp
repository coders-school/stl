#pragma once

#include <algorithm>
#include <array>
#include <vector>
#include <iterator>

constexpr size_t height = 32;
constexpr size_t width = 32;


using Image = const std::array<std::array<uint8_t, width>, height>&;

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(Image compress);

std::array<std::array<uint8_t, width>, height> decompressGrayscale(const std::vector<std::pair<uint8_t, uint8_t>>& compressedMap);

void printMap(const std::array<std::array<uint8_t, width>, height>& mapToPrint);
