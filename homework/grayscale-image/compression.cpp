#include "compression.hpp"
#include <iostream>

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, width>, height>& arr) {
    std::vector<std::pair<uint8_t, uint8_t>> vec;
    vec.reserve(height * width);

    for (const auto& row : arr) {
        uint8_t currentElement = row.front();
        uint8_t counter = 1;

        for (auto it = cbegin(row)+1; it != cend(row); it++) {
            if (currentElement != *it) {
                vec.push_back(std::make_pair(currentElement, counter));
                currentElement = *it;
                counter = 1;
                continue;
            } 
            
            counter++;            
        }

        vec.push_back(std::make_pair(currentElement, counter));
    }

    vec.shrink_to_fit();
    return vec;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(const std::vector<std::pair<uint8_t, uint8_t>>& vec) {
    std::array<std::array<uint8_t, width>, height> arr;

    auto x = 0;
    auto y = 0;

    for (auto el : vec) {
        std::fill(&arr[x][y], &arr[x][y + el.second], el.first);
        y += el.second;
        if (y >= width) {
            x++;
            y = 0;
        }
    }

    return arr;
}

void printMap(const std::array<std::array<uint8_t, width>, height>& arr) {
    for (const auto& row : arr) {
        for (const auto el : row) {
            if (std::isprint(el)) {
                std::cout << el;
            } else {
                std::cout << ' ';
            }
        }
        std::cout << '\n';
    }
}
