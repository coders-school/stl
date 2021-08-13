#pragma once

#include <array>
#include <vector>
#include <cstdint>
#include <utility>

using std::uint8_t;
using std::size_t;

inline constexpr size_t width{ 32 };
inline constexpr size_t height{ 32 };

using Bitmap = std::array<std::array<uint8_t, width>, height>;
using CompressedBitmap = std::vector<std::pair<uint8_t, uint8_t>>;

Bitmap decompressGrayscale(const CompressedBitmap&);
CompressedBitmap compressGrayscale(const Bitmap&);
