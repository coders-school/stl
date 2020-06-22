#include <array>
#include <vector>

namespace {
constexpr uint8_t width = 32;
constexpr uint8_t height = 32;
}  

using BitmapPGM = std::array<std::array<uint8_t, width>, height>;
using CompressedPGM = std::vector<std::pair<uint8_t, uint8_t>>;

CompressedPGM compressGrayscale(BitmapPGM&);
BitmapPGM decompressGrayscale(CompressedPGM&);
void printMap(BitmapPGM&);
