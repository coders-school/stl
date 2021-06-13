#include <iostream>
#include <array>
#include <vector>
#include <utility>
#include <functional>

constexpr size_t width = 32;
constexpr size_t height = 32;

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, height>, width>& bitMap);
std::array<std::array<uint8_t, height>, width> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>>& compress);