#pragma once
#include <array>
#include <algorithm>
#include <utility>  // for std::pair<>
#include <vector>
#include <cstdint>

constexpr size_t width = 32;
constexpr size_t height = 32;

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height> arg);
std::array<std::array<uint8_t, width>, height> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>> arg);