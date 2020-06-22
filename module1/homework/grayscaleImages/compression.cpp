#include "compression.hpp"

#include <algorithm>
#include <cctype>
#include <iostream>
#include <iterator>

CompressedImage compressGrayscale(const Image& bitmap) {
    CompressedImage compressedBitmap{};

    std::for_each(cbegin(bitmap),
                  cend(bitmap),
                  [&compressedBitmap](const auto& row) {
                      auto iterStart = begin(row);
                      auto iterFound = iterStart;
                      while (iterFound != end(row)) {
                          iterFound = std::find_if(iterStart,
                                                   end(row),
                                                   [&iterStart](const auto el) {
                                                       return el != *iterStart;
                                                   });
                          compressedBitmap.push_back({*iterStart, std::distance(iterStart, iterFound)});
                          iterStart = iterFound;
                      }
                  });

    compressedBitmap.shrink_to_fit();

    return compressedBitmap;
}

Image decompressGrayscale(const CompressedImage& compressedBitmap) {
    Image decompressedBitmap{};

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

void printMap(const Image& bitmap) {
    constexpr uint8_t space = ' ';
    constexpr uint8_t newLine = '\n';

    std::transform(std::begin(bitmap),
                   std::end(bitmap),
                   std::ostream_iterator<uint8_t>(std::cout),
                   [](const auto& row) {
                       std::transform(std::begin(row),
                                      std::end(row),
                                      std::ostream_iterator<uint8_t>(std::cout),
                                      [](const uint8_t el) {
                                          if (std::isprint(el)) {
                                              return el;
                                          } else {
                                              return space;
                                          }
                                      });
                       return newLine;
                   });
}
