#pragma once
#include <array>
#include <vector>

using pairVector = std::vector<std::pair<uint8_t, uint8_t>>;

constexpr size_t width = 32;
constexpr size_t height = 32;

pairVector compressGrayscale(const std::array<std::array<uint8_t, width>, height>&);
std::array<std::array<uint8_t, width>, height> decompressGrayscale(const pairVector&);
void printMap(const std::array<std::array<uint8_t, width>, height>&);
