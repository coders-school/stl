#include "compression.hpp"
#include <cstddef>
#include <utility>
#include <vector>

std::vector<std::pair<uint8_t, uint8_t>>
compressGrayscale(std::array<std::array<uint8_t, 240>, 160> array) {
  std::vector<std::pair<uint8_t, uint8_t>> compressed{};
  compressed.reserve(array.size());

  for (const auto &el : array) {
    size_t counter{0};
    for (auto e : el) {
      while (e == e - 1) {
        counter++;
      }
      compressed.emplace_back(std::make_pair(e, counter));
    };
  };
  compressed.shrink_to_fit();
  return compressed;
}


  std::array<std::array<uint8_t, 240>, 160>
decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>> compressed) {

    std::array<std::array<uint8_t, 240>, 160> decompressed{0};

    return decompressed;
  };
