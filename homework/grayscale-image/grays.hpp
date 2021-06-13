#pragma once
#include <vector>
#include <array>
#include <forward_list>

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, 240>, 160>);
std::array<std::array<uint8_t, 240>, 160> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>>);