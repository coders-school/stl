#include "compression.hpp"

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height> image){
    return std::vector<std::pair<uint8_t, uint8_t>>{std::make_pair(0, width*height)};
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>> pack) {
    std::array<uint8_t, width> line;
    line.fill(0);
    std::array<std::array<uint8_t, width>, height> rect;
    rect.fill(line);
    return rect;
}