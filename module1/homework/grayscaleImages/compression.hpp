#include <array>
#include <vector>

constexpr int height = 160;
constexpr int width = 240;
constexpr int ninjaHeight = 32;
constexpr int ninjaWidth = 32;

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height>& bitmap);
std::array<std::array<uint8_t, width>, height> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>>& compressedData);
void printMap(std::array<std::array<uint8_t, ninjaWidth>, ninjaHeight>& bitmap);