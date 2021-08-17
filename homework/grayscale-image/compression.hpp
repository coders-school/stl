#pragma once
#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
#include <utility>
constexpr size_t width = 0;
constexpr size_t height = 0;

using board2d =  std::array<std::array<uint8_t, width>, height>;
using pairUint = std::vector<std::pair<uint8_t, uint8_t>>;

pairUint compressGrayscale(board2d);
board2d decompressGrayscale(pairUint);
pairUint mergeVector(std::vector<uint8_t>, std::vector<uint8_t>);
std::vector<int> compress(std::vector<int>);


