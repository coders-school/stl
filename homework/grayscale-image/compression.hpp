#include <array>
#include <iostream>
#include <vector>

constexpr size_t width = 240;
constexpr size_t height = 160;

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, width>, height>& arr);
std::array<std::array<uint8_t, width>, height> decompressGrayscale(const std::vector<std::pair<uint8_t, uint8_t>>& vec);
void printMap(const std::array<std::array<uint8_t, 32>, 32>& arr);