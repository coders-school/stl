#include <array>
#include <vector>

constexpr int height = 160;
constexpr int width = 240;
constexpr int imageHeight = 32;
constexpr int imageWidth = 32;

using uint8_tPair = std::pair<uint8_t, uint8_t>;
using bitmapType = std::array<std::array<uint8_t, width>, height>;
using compressedArray = std::array<std::array<uint8_t, width>, height>;
using imageBitmap = std::array<std::array<uint8_t, imageWidth>, imageHeight>;

std::vector<uint8_tPair> compressGrayscale(bitmapType& bitmap);
compressedArray decompressGrayscale(std::vector<uint8_tPair>& compressedData);
void printMap(imageBitmap& bitmap);
