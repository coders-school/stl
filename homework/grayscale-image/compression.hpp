#pragma once

#include <array>
#include <vector>
#include <utility>

using uint8_t = unsigned char;
constexpr size_t width = 240;
constexpr size_t height = 160;


std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, 240>, 160>);


std::array<std::array<uint8_t, 240>, 160>decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>>);
