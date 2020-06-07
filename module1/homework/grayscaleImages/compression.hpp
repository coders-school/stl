#pragma once

#include <array>
#include <cstdint>
#include <utility>
#include <vector>

constexpr size_t width = 32;
constexpr size_t height = 32;

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, width>, height>&);
std::array<std::array<uint8_t, width>, height> decompressGrayscale(const std::vector<std::pair<uint8_t, uint8_t>>&);
std::string printMap(const std::vector<std::pair<uint8_t, uint8_t>>&);
