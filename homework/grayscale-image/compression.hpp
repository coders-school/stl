#include <array>
#include <cstdint>
#include <vector>

constexpr size_t height = 160;
constexpr size_t width = 240;

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, width>, height>& );
std::array<std::array<uint8_t, width>, height> decompressGrayscale(const std::vector<std::pair<uint8_t, uint8_t>>& );