#include <array>
#include <cstdint>
#include <vector>


constexpr size_t width = 32;
constexpr size_t height = 32;
std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, 240>, 160> bmap);