#ifndef COMPRESSION_HPP
#define COMPRESSION_HPP

#include <array>
#include <vector>
#include <utility>
#include <cstdint>

constexpr size_t width = 32;//240;
constexpr size_t height = 32;//160;

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height> to_compress);
std::array<std::array<uint8_t, width>, height> decompressGrayscale (std::vector<std::pair<uint8_t, uint8_t>> to_decompress);

#endif
