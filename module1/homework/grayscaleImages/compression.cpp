#include "compression.hpp"
#include <sstream>

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(
    const std::array<std::array<uint8_t, width>, height>& bitmap) {
    std::vector<std::pair<uint8_t, uint8_t>> compressed_bitmap;
    for (int i = 0; i < height; ++i) {
        int sequence_begin = 0;
        for (int j = 1; j < width; ++j) {
            if (bitmap[i][j] != bitmap[i][j - 1]) {
                compressed_bitmap.push_back(
                    std::make_pair(bitmap[i][j - 1], j - sequence_begin));
                sequence_begin = j;
            }
        }
        compressed_bitmap.push_back(
            std::make_pair(bitmap[i][width - 1], width - sequence_begin));
    }

    return compressed_bitmap;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(
    const std::vector<std::pair<uint8_t, uint8_t>>& compressed_bitmap) {
    std::array<std::array<uint8_t, width>, height> decompressed_bitmap;
    int i = 0;
    int j = 0;
    for (const auto& el : compressed_bitmap) {
        auto value = el.first;
        auto quantity = el.second;
        do {
            decompressed_bitmap[i][j++] = value;
            quantity--;
        } while (quantity > 0);
        if (j >= width) {
            i++;
            j = 0;
        }
    }

    return decompressed_bitmap;
}

std::string printMap(const std::vector<std::pair<uint8_t, uint8_t>>& compressed_bitmap) {
  auto ss = std::stringstream {};
  for (size_t it = 0; it < compressed_bitmap.size(); it++) {
    for (size_t it2 = 0; it2 < compressed_bitmap[it].first; it2++) {
      ss << std::to_string(compressed_bitmap[it].second);
    }
  }

  return ss.str();
}
