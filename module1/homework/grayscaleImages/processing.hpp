#pragma once

#include <array>
#include <vector>

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, 240>, 160>);  //TODO: Name for the parameter

std::array<std::array<uint8_t, 240>, 160> decompressGrayscale(const std::vector<std::pair<uint8_t, uint8_t>>& compressedMap);
