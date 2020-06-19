#include "compression.hpp"

#include <algorithm>
#include <cctype>
#include <iostream>

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(
    const std::array<std::array<uint8_t, width>, height>& bitmap) {
    std::vector<std::pair<uint8_t, uint8_t>> compressedBitmap{};

    for (const auto& row : bitmap) {
        auto iterStart = begin(row);
        auto iterFound = begin(row);
        while (iterFound != end(row)) {
            iterFound = std::find_if(iterStart,
                                     end(row),
                                     [&iterStart](const auto el) {
                                         return el != *iterStart;
                                     });
            compressedBitmap.push_back({*iterStart, std::distance(iterStart, iterFound)});
            iterStart = iterFound;
        }
    }

    return compressedBitmap;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(
    const std::vector<std::pair<uint8_t, uint8_t>>& compressedBitmap) {
    std::array<std::array<uint8_t, width>, height> decompressedBitmap{};

    auto iterRow = begin(decompressedBitmap);
    auto iterEl = begin(*iterRow);

    std::for_each(cbegin(compressedBitmap),
                  cend(compressedBitmap),
                  [&iterRow, &iterEl](const auto& el) {
                      iterEl = std::fill_n(iterEl, el.second, el.first);
                      if (iterEl == end(*iterRow)) {
                          iterRow++;
                      }
                  });

    return decompressedBitmap;
}

void printMap(const std::array<std::array<uint8_t, width>, height>& bitmap) {
    for (const auto& row : bitmap) {
        for (const auto el : row) {
            if (std::isprint(el)) {
                std::cout << el;
            } else {
                std::cout << ' ';
            }
        }
        std::cout << '\n';
    }
}
