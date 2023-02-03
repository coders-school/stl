#pragma once

#include <stdint.h>
#include <algorithm>
#include <array>
#include <cstdint>

#include <vector>

#include "compressGrayscale.hpp"

std::array<std::array<uint8_t, width>, height> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>>& v);