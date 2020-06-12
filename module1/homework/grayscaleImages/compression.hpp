#pragma once

#include <array>
#include <vector>

constexpr uint32_t height = 32; //160;
constexpr uint32_t width = 32; //240;

void printMap (std::array<std::array<uint8_t, width>, height> bitmap);
std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale (std::array<std::array<uint8_t, width>, height> bitmap);


std::array<std::array<uint8_t, width>, height> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>> compressed);