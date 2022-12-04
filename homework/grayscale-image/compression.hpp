#pragma once

#include <array>
#include <cstddef>
#include <cstdint>
#include <utility>
#include <vector>

constexpr size_t width = 32;
constexpr size_t height = 32;

std::vector<std::pair<uint8_t, uint8_t>>
compressGrayscale(const std::array<std::array<uint8_t, width>, height>&);

std::array<std::array<uint8_t, 240>, 160>
decompressGrayscale(const std::vector<std::pair<uint8_t, uint8_t>>&);
