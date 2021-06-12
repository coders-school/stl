#pragma once
#include <vector>
#include <utility>
#include <iostream>
#include <array>

constexpr size_t width = 32;
constexpr size_t height = 32;

std::vector<std::pair<u_int8_t, u_int8_t>> compressGrayscale(const std::array<std::array<uint8_t, width>, height>& arr);
///  JESZCZE NIE ZROBIONE
std::array<std::array<uint8_t, width>, height> decompressGrayscale(const std::vector<std::pair<uint8_t, uint8_t>>& vec);
void printMap(const std::array<std::array<uint8_t, width>, height>& arr);