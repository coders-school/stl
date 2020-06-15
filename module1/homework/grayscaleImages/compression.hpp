#include <array>
#include <cstdint>
#include <vector>

constexpr size_t width = 32;
constexpr size_t height = 32;

using image = std::array<std::array<uint8_t, width>, height>;
using compressedImage = std::vector<std::pair<uint8_t, uint8_t>>;

compressedImage compressGrayscale(const image& bitmap);
image decompressGrayscale(const compressedImage& compression);
void printMap(const image& bitmap);
