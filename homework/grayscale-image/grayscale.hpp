#pragma once
#include <array>
#include <vector>
#include <iostream>
constexpr size_t width = 5;
constexpr size_t height = 2;


std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height> array_1);
std::array<std::array<uint8_t, width>, height> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>>array_2);
void printMap(std::array<std::array<uint8_t, width>, height>);