#include "compression.hpp"
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <iostream>
#include <iterator>
#include <utility>
#include <vector>

std::vector<std::pair<uint8_t, uint8_t>>
compressGrayscale(std::array<std::array<uint8_t, width>, height> array) {
  std::vector<std::pair<uint8_t, uint8_t>> compressed{};
  compressed.reserve(width*height);

  uint8_t counter{1};
  for (const auto &el : array) {
    for (auto pixel = el.cbegin(); pixel != el.cend(); pixel++) {
      if (*pixel != *(std::next(pixel)) || pixel == std::prev(el.end())) {
        compressed.emplace_back(std::make_pair(static_cast<uint8_t>(*pixel), counter));
        std::cout << "|" << int(*pixel) << ' ' << int(counter) << "|";
        counter = 1;
      } else {
        counter++;
      }
    }
    std::cout << '\n';
  }
  compressed.shrink_to_fit();
  return compressed;
}

std::array<std::array<uint8_t, width>, height>
decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>> compressed) {

  std::array<std::array<uint8_t, width>, height> decompressed{0};

  return decompressed;
};
