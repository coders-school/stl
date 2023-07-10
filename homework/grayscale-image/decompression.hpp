#include <array>
#include <cstdint>
#include <iostream>
#include <vector>

//constexpr size_t width = 32;     //32;
//constexpr size_t height = 32;   //32;
std::array<std::array<uint8_t, 240>, 160> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>> bmap);
