#include "compression.hpp"

#include <algorithm>

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, width>, height>& bitmap) {
    std::vector<std::pair<uint8_t, uint8_t>> compressedVector;
    compressedVector.reserve(width * height);
    auto nextCharacter = '0';
    std::for_each(bitmap.begin(), bitmap.end(), [&](const auto& line) {
        nextCharacter = '0';
        std::for_each(line.begin(), line.end(), [&](const auto character) {
            if(character != nextCharacter) {
                compressedVector.push_back(std::make_pair(character, 1));
            }
            else {
                compressedVector[compressedVector.size() - 1].second += 1;
            }
            nextCharacter = character;
        });
    });

    return compressedVector;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(const std::vector<std::pair<uint8_t, uint8_t>>& bitmap) {
    std::array<std::array<uint8_t, width>, height> arr;
    auto counter = 0;
    auto iter = bitmap.begin();
    int next = static_cast<int>(iter->second);
    while (++counter < width * height) {
        if (counter == next) {
            iter++;
            next += iter->second;
        }
        arr[counter / width][counter % width] = iter->first;
    }
    return arr;
}

// void printMap(const std::array<std::array<uint8_t, width>, height>& ninja) {
//     for (const auto& line : ninja) {
//         for (const auto& el : line) {
//             if (el <= ' ') {
//                 std::cout << ' ';
//             } else {
//                 std::cout << el;
//             }
//         } 
//         std::cout << '\n';
//     }
// }
