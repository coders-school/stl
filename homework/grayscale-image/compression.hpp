#pragma once

#include <array>
#include <vector>
#include <utility>

using uint8_t = unsigned char;
using bitmap = std::array<std::array<uint8_t, 240>, 160>;
using compressed_bitmap = std::vector<std::pair<uint8_t, uint8_t>> ;

compressed_bitmap compressGreyscale(bitmap);

