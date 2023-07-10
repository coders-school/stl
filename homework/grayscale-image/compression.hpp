#include <array>
#include <cstdint>
#include <iostream>
#include <vector>

 
 constexpr size_t width = 3;  // 32;
 constexpr size_t height = 10;    //32;
//height = 240 , width = 160
std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, height>, width> bmap);
