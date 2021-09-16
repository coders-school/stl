//#include "compressGrayscale.cpp"
#include <array>
#include <cstdint>
#include <utility>
#include <vector>
constexpr size_t width = 240;
constexpr size_t height = 160;
std::vector<std::pair<uint8_t, uint8_t>>
compressGrayscale(std::array<std::array<uint8_t, 240>, 160> array);

std::array<std::array<uint8_t, 240>, 160>
decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>> compressed);