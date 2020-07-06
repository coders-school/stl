#pragma once

#include <array>
#include <utility>
#include <vector>

constexpr size_t width = 32;
constexpr size_t height = 32;

void printMap(const std::array<std::array<uint8_t, height>, width>& input);
void printVectorOfPairs(const std::vector<std::pair<uint8_t, uint8_t>>& input);
std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(
    const std::array<std::array<uint8_t, height>, width>& input);
std::array<std::array<uint8_t, height>, width> decompressGrayscale(
    const std::vector<std::pair<uint8_t, uint8_t>>& input);
