#include "compression.hpp"
#include <algorithm>
#include <array>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <iostream>
#include <iterator>
#include <utility>
#include <vector>

std::vector<std::pair<uint8_t, uint8_t>>
compressGrayscale(std::array<std::array<uint8_t, width>, height> &array) {
  std::vector<std::pair<uint8_t, uint8_t>> compressed{};
  compressed.reserve(width * height);

  compressed.shrink_to_fit();
  return compressed;
}

std::array<std::array<uint8_t, width>, height>
decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>> compressed) {

  std::array<std::array<uint8_t, width>, height> decompressed{};
  auto pix = decompressed.begin()->begin();

  std::for_each(begin(compressed), end(compressed),
                [](auto decompressed, auto compressed) {
                  return std::fill_n(std::back_inserter(decompressed.begin()),
                                     compressed.second, compressed.first);
                });

  return decompressed;
};