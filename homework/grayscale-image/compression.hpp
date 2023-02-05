#pragma once
#include <array>
#include <cstdint>
#include <iostream>
#include <utility>
#include <vector>

constexpr size_t width = 32; // 240
constexpr size_t height = 32; // 160

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height> &arr);
std::array<std::array<uint8_t, width>, height> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>> &arr);
// void printMap(std::array<std::array<uint8_t, width>, height> &arr);