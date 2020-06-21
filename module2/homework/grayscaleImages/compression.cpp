#include "compression.hpp"

#include <algorithm>
#include <cctype>
#include <iostream>

// This code was created only to not use any loops, but algorithms.
std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(
    const std::array<std::array<uint8_t, width>, height>& bitmap) {
    
    std::vector<std::vector<uint8_t>> vectors;
    std::transform(bitmap.begin(),
                   bitmap.end(),
                   std::back_inserter(vectors),
                   [](const auto& row) {
                       std::vector<uint8_t> single_row;
                       std::transform(row.begin(),
                                      row.end(),
                                      std::back_inserter(single_row),
                                      [](const auto& single_value) {
                                          return single_value;
                                      });
                       return single_row;
                   });

    std::vector<std::vector<std::pair<uint8_t, uint8_t>>> vector_pairs;
    std::transform(vectors.begin(),
                   vectors.end(),
                   std::back_inserter(vector_pairs),
                   [](auto row) {
                       auto last = std::unique(row.begin(), row.end());
                       row.erase(last, row.end());
                       std::vector<std::pair<uint8_t, uint8_t>> pairs;
                       std::transform(row.begin(),
                                      row.end(),
                                      std::back_inserter(pairs),
                                      [](auto& el) {
                                          return std::make_pair(el, 0);
                                      });
                       return pairs;
                   });

    std::transform(vector_pairs.begin(),
                   vector_pairs.end(),
                   vectors.begin(),
                   vector_pairs.begin(),
                   [](auto& row1, const auto& row2) {
                       auto iter = row2.begin();
                       std::transform(row1.begin(),
                                      row1.end(),
                                      row1.begin(),
                                      [&row2, &iter](auto& pair1) {
                                          auto cur = pair1.first;
                                          uint8_t count = 0;
                                          auto last = std::find_if(iter, row2.end(), [&cur](auto& ch) { return ch != cur; });
                                          count = std::distance(iter, last);
                                          std::advance(iter, count);
                                          return std::make_pair(cur, count);
                                      });
                       return row1;
                   });

    std::vector<std::pair<uint8_t, uint8_t>> compressed_bitmap;
    std::for_each(vector_pairs.begin(),
                  vector_pairs.end(),
                  [&compressed_bitmap](const auto& row) {
                      std::for_each(row.begin(),
                                    row.end(),
                                    [&compressed_bitmap](const auto& el) {
                                        compressed_bitmap.push_back(el);
                                    });
                  });

    return compressed_bitmap;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(
    const std::vector<std::pair<uint8_t, uint8_t>>& compressed_bitmap) {
    std::array<std::array<uint8_t, width>, height> decompressed_bitmap;
    auto it = decompressed_bitmap.front().begin();
    std::for_each(compressed_bitmap.begin(), compressed_bitmap.end(), [&it](auto pair) {
        it = std::fill_n(it, pair.second, pair.first);
    });

    return decompressed_bitmap;
}

void printMap(const std::array<std::array<uint8_t, width>, height>& decompressed_bitmap) {
    for (const auto& row : decompressed_bitmap) {
        for (const auto& ch : row) {
            if (std::isprint(ch)) {
                std::cout << ch;
            }
            else {
                std::cout << ' ';
            }
        }
        std::cout << '\n';
    }
}
