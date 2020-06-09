#include "compression.hpp"

#include <sstream>

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(
    const std::array<std::array<uint8_t, width>, height>& bitmap) {
    std::vector<std::pair<uint8_t, uint8_t>> compressed_bitmap;
    for (size_t i = 0; i < height; ++i) {
        uint8_t previous = bitmap[i][0], count = 1;
        for (size_t j = 1; j < width; ++j) {
            if (bitmap[i][j] == previous) {
                count++;
            }
            if (bitmap[i][j] != previous || j == width - 1) {
                compressed_bitmap.push_back({previous, count});
                previous = bitmap[i][j];
                count = 1;
            }
        }
    }
    return compressed_bitmap;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(
    const std::vector<std::pair<uint8_t, uint8_t>>& compressed_bitmap) {
    std::array<std::array<uint8_t, width>, height> decompressed_bitmap;
    int i = 0, j = 0;
    for (auto element : compressed_bitmap) {
        auto value = element.first;
        auto quantity = element.second;

        do {
            decompressed_bitmap[i][j++] = value;
            quantity--;
            if (j == width) {
                i++;
                j = 0;
            }

        } while (quantity >= 1);
    }

    return decompressed_bitmap;
}

std::string printMap(const std::vector<std::pair<uint8_t, uint8_t>>& compressed_bitmap) {
    auto ss = std::stringstream{};
    for (size_t it = 0; it < compressed_bitmap.size(); it++) {
        for (size_t it2 = 0; it2 < compressed_bitmap[it].second; it2++) {
            ss << std::to_string(compressed_bitmap[it].first);
        }
    }
    return ss.str();
}

std::string printMap(const std::array<std::array<uint8_t, width>, height>& deompressed_bitmap) {
    auto ss = std::stringstream{};
    for (const auto& it : deompressed_bitmap) {
        for (const auto& it2 : it) {
            ss << it2;
        }
        ss << '\n';
    }
    return ss.str();
}
