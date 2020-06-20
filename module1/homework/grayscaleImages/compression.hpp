#pragma once

#include <array>
#include <vector>

constexpr size_t width = 32;
constexpr size_t height = 32;
constexpr uint8_t ASCIIspace = ' ';

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, height>, width>& dataToCompress);
std::array<std::array<uint8_t, height>, width> decompressGrayscale(const std::vector<std::pair<uint8_t, uint8_t>>& dataTodecompress);
void printMap(const std::array<std::array<uint8_t, height>, width>& mapToPrint);
