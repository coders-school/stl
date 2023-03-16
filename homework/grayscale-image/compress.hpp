#include <algorithm>
#include <iostream>
#include <array>
#include <vector>


const int width = 32;
const int height = 32;
std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale (std::array<std::array<uint8_t, width>, height>& );
// std::array<std::array<uint8_t, width>, height> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>>& );