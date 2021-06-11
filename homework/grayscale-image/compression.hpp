#pragma once

#include <vector>
#include <array>
#include <utility> 

#include <cctype>
#include <iostream>

constexpr size_t width = 32;
constexpr size_t height = 32;

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height> image);

std::array<std::array<uint8_t, width>, height> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>> pack);

void printCode(uint8_t code);

template <size_t WIDTH, size_t HEIGHT>
void printMap(std::array<std::array<uint8_t, WIDTH>, HEIGHT> map) {
    for (const auto& line : map) {
        for (const auto& point : line) {
            printCode(point);
        }
        std::cout << '\n';
    }
}

void printCompresedMap(std::vector<std::pair<uint8_t, uint8_t>> compressed, size_t width);