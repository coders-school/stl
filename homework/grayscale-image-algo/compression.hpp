#pragma once
#include <array>
#include <utility>  //pair
#include <vector>

constexpr size_t width = 32;   // 32;
constexpr size_t height = 32;  // 32;
// height = 240 , width = 160
std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, width>, height>& bmap);
// std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, width>, height> &arr);
std::array<std::array<uint8_t, width>, height> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>>& arr);