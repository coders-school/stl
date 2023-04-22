#include <array>
#include <cstddef>
#include <cstdint>
#include <utility>  // for std::pair<>
#include <vector>
constexpr size_t width = 32;
constexpr size_t height = 32;

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, 32>, 32>& arr);

std::array<std::array<uint8_t, 32>, 32> decompressGrayscale(const std::vector<std::pair<uint8_t, uint8_t>>& vec);