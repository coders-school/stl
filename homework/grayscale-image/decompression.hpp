#include <array>
#include <cstdint>
#include <iostream>
#include <vector>

// extern size_t width = 32 ;     //32;
 //extern size_t height = 32;   //32;
std::array<std::array<uint8_t, 32>, 32> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>> bmap);
