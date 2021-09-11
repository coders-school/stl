
#pragma once
#include <vector>
#include <stdint.h>
#include <array>
#include <algorithm>

constexpr size_t width = 32;
constexpr size_t height = 32;



using FractionVector = std::vector<std::pair<uint8_t, uint8_t>>;
using FractionArray = std::array<std::array<uint8_t, width>, height>;

void printMap(const std::array<std::array<uint8_t, width>, height>& arr);

FractionVector compressGrayscale(const FractionArray&);
FractionArray decompressGrayscale(const FractionVector&);

