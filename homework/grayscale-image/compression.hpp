#pragma once

#include <array>
#include <utility>
#include <vector>

constexpr std::size_t width = 32;
constexpr std::size_t height = 32;

std::vector<std::pair<std::uint8_t, std::uint8_t>> compressGrayscale(std::array<std::array<std::uint8_t, width>, height> picture);
std::array<std::array<std::uint8_t, width>, height> decompressGrayscale(std::vector<std::pair<std::uint8_t, std::uint8_t>> picture);
void printMap(std::array<std::array<std::uint8_t, width>, height> picture);
