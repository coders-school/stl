#include "compression.hpp"

#include <algorithm>
#include <iostream>
#include <utility>

uint8_tPairVector compressGrayscale(bitMapType& bitMapWithNinja) {
    uint8_tPairVector compressedNinja;
    compressedNinja.reserve(width * height);

    std::for_each(bitMapWithNinja.begin(), bitMapWithNinja.end(), [&compressedNinja](auto row) {
        int color = row.front();
        int counter{};

        for (auto it = row.begin(); it != row.end(); it++) {
            if (color == *it) {
                counter++;
            }
            if (color != *it || it == (row.end() - 1)) {
                compressedNinja.emplace_back(color, counter);
                counter = 1;
            }
            color = *it;
        }
    });
    compressedNinja.shrink_to_fit();

    return compressedNinja;
}

bitMapType decompressGrayscale(uint8_tPairVector& compressedNinja) {
    bitMapType bitMapWithNinja;
    int row{};
    int pairNumber{};

    std::for_each(compressedNinja.cbegin(), compressedNinja.cend(), [&](auto& pair) {
        std::fill_n(std::next(bitMapWithNinja[row].begin(), pairNumber), pair.second, pair.first);
        pairNumber += pair.second;

        if (pairNumber >= width) {
            pairNumber = 0;
            row++;
        }
    });
    return bitMapWithNinja;
}

void printMap(bitMapType& bitMapWithNinja) {
    for (const auto& row : bitMapWithNinja) {
        for (const auto& element : row) {
            if (std::iscntrl(element)) {
                std::cout << " ";
            } else
                std::cout << element;
        }
        std::cout << '\n';
    }
}