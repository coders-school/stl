#include <algorithm>
#include <array>
#include <cstdint>
#include <iostream>
#include <vector>
constexpr size_t width = 32;
constexpr size_t height = 32;

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, height>, width>& arr);
std::array<std::array<uint8_t, 32>, 32> decompressGrayscale(const std::vector<std::pair<uint8_t, uint8_t>>& vec);