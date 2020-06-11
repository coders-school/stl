#include "compression.hpp"

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, width>, height>& arr) {
    std::vector<std::pair<uint8_t, uint8_t>> vec;
    uint8_t counter;
    uint8_t buffer;
    for (const auto& ln : arr) {
        counter = 0;
        buffer = ln.at(0);
        for (const auto& el : ln) {
            if (buffer == el) {
                counter++;
            } else {
                vec.push_back(std::make_pair(buffer, counter));
                counter = 1;
                buffer = el;
            }
        }
        vec.push_back(std::make_pair(buffer, counter));
    }

    return vec;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(const std::vector<std::pair<uint8_t, uint8_t>>& vec) {
    std::array<std::array<uint8_t, width>, height> arr;
    uint8_t counter;
    uint8_t line = 0;
    for (const auto& el : vec) {
        if (counter >= width) {
            counter = 0;
            ++line;
        }
        for (size_t i = counter; i < counter + el.second; i++) {
            arr[line][i] = el.first;
        }
        counter += el.second;
    }

    return arr;
}

void printMap(std::array<std::array<uint8_t, width>, height>& bitmap) {
}