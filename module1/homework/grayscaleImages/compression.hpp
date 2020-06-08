#pragma once
#include <array>
#include <utility>  // for std::pair<>
#include <vector>

constexpr size_t height = 32; //160
constexpr size_t width = 32; //240

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, width>, height>& imgToCompress);
void printMap(const std::array<std::array<uint8_t, width>, height>& bitmap);