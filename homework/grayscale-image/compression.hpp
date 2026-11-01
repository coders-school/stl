#ifndef COMPRESSION_HPP
#define COMPRESSION_HPP

#include <array>  // C++11
#include <cstdint>
#include <utility>
#include <vector>

constexpr std::size_t width = 32;
constexpr std::size_t height = 32;

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, width>, height>& bitmap);

std::array<std::array<uint8_t, width>, height> decompressGrayscale(const std::vector<std::pair<uint8_t, uint8_t>>
                                                                       compressed);

#endif
