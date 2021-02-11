#pragma once
#include <algorithm>
#include <array>
#include <vector>
#include <iostream>

constexpr size_t width = 32;
constexpr size_t height = 32;

using vectorPair = std::vector<std::pair<uint8_t, uint8_t>>;
using arrayMap = std::array<std::array<uint8_t, height>, width>;

vectorPair compressGrayscale(arrayMap);
arrayMap decompressGrayscale(vectorPair);
void printMap(arrayMap&);
