
#include <array>
#include <cstdint>
#include <utility>
#include <vector>
constexpr size_t width = 32; //240
constexpr size_t height = 32; //160
std::vector<std::pair<uint8_t, uint8_t>>
compressGrayscale(std::array<std::array<uint8_t, width>, height> array);

std::array<std::array<uint8_t, width>, height>
decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>> compressed);