#ifndef COMPRESSION_HPP
#define COMPRESSION_HPP

#include <array>
#include <cstdint>
#include <utility>
#include <vector>

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, 32>, 32>& img);

#endif
