#pragma once

#include <utility> // pair
#include <vector>
#include <array>

constexpr size_t width = 32; //test 10
constexpr size_t height = 32; //test 3

using arrayPicture = std::array<std::array<uint8_t, width>, height>;
using vectorPicture = std::vector<std::pair<uint8_t, uint8_t>>;

vectorPicture compressGrayscale(arrayPicture&);
arrayPicture decompressGrayscale(vectorPicture&);
