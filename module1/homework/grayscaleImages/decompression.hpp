#pragma once 
#include <vector>
#include <utility>
#include <array>

std::array<std::array<uint8_t, 32>, 32> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>> bitmap);