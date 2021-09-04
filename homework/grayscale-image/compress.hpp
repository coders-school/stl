
#pragma once
#include <vector>
#include <stdint.h>
#include <array>
#include <algorithm>

constexpr size_t width = 32;
constexpr size_t height = 32;

extern uint8_t ActualColor  ;
extern uint8_t counter ;

using Fracton = std::array<std::array<uint8_t, width>, height>;


std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(Fracton arr);
void printMap(std::vector<std::pair<uint8_t, uint8_t>> vec);


void printMap(const std::array<std::array<uint8_t, width>, height>& arr);

std::array<std::array<uint8_t, width>, height> decompressGrayscale(const std::vector<std::pair<uint8_t, uint8_t>>&);