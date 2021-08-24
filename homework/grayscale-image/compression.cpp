#include "compression.hpp"
#include <algorithm>
#include <iostream>

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, width>, height> &uncompressed)
{
    std::vector<std::pair<uint8_t, uint8_t>> compressed;
    compressed.reserve(width * height);
    std::for_each(uncompressed.begin(),
                  uncompressed.end(),
                  [&compressed](auto row){
                      for(auto uniqueElementIt = row.begin(); uniqueElementIt != row.end();) {
                          auto nextUniqueElement = std::find_if(uniqueElementIt,
                                                                row.end(),
                                                                [&uniqueElementIt](auto x){ return x != *uniqueElementIt; });
                          compressed.push_back(std::make_pair(*uniqueElementIt,
                                                              std::count_if(uniqueElementIt, 
                                                                            nextUniqueElement,
                                                                            [&uniqueElementIt](auto x){ return x == *uniqueElementIt; })));
                          uniqueElementIt = nextUniqueElement;
                      }
    });
    return compressed;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(const std::vector<std::pair<uint8_t, uint8_t>> &compressed)
{
    std::array<std::array<uint8_t, width>, height> decompressed;
    auto it = begin(decompressed)->begin();
    std::for_each(compressed.begin(), compressed.end(), [&it](auto pair) {
                                                                std::fill_n(it, pair.second, pair.first);
                                                                it = std::next(it, pair.second); });
    return decompressed;
}

// void printMap(const std::array<std::array<uint8_t, width>, height>& arr) {
//     const uint8_t lowestChar{31};
//     for (const auto& row : arr) {
//         for (const auto& character : row) {
//             if (character <= lowestChar) {
//                 std::cout << ' ';
//             } else {
//                 std::cout << character;
//             }
//         }
//         std::cout << '\n';
//     }
// }
