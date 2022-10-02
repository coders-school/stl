
#include <vector>
#include <array>
#include <cstdint>
#include <cwchar>
#include <optional>

constexpr size_t width = 32;
constexpr size_t height = 32;

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height>);
std::array<std::array<uint8_t, width>, height> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>> input);

std::vector<std::pair<uint8_t, uint8_t>> compress_single_line(const std::array<uint8_t, width>& v);
std::tuple<bool, uint8_t, int> get_char_from_input(const std::vector<std::pair<uint8_t, uint8_t>>& input, int chunk_number);
std::tuple<bool, uint8_t, int> get_char_from_chunk(const std::pair<uint8_t, uint8_t>& chunk, int character_counter);

