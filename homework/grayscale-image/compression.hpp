#include <array>
#include <vector>

constexpr size_t width = 32;
constexpr size_t height = 32;

using Image = std::array<std::array<uint8_t, width>, height>;
using CompressedImage = std::vector<std::pair<uint8_t, uint8_t>>;

CompressedImage compressGrayscale(const Image&);
Image decompressGrayscale(const CompressedImage&);
