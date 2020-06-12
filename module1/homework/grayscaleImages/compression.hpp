#include <vector>
#include <array>

constexpr int height = 160;
constexpr int width = 240;

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, 240>, 160>& bitmap);
std::array<std::array<uint8_t, 240>, 160> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>>& compressedData);
