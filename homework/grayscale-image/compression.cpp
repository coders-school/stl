#include "compression.hpp"

#include <algorithm>

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, width>, height>& bitmap) {
    std::vector<std::pair<uint8_t, uint8_t>> compressedVector;
    compressedVector.reserve(width * height);
    auto nextCharacter = ' ';

    std::for_each(bitmap.cbegin(), bitmap.cend(), [&](const auto& line) {
        std::for_each(line.cbegin(), line.cend(), [&](const auto character) {
            if(character != nextCharacter) {
                compressedVector.push_back(std::make_pair(character, 1));
            }
            else {
                compressedVector[compressedVector.size() - 1].second += 1;
            }
            nextCharacter = character;
        });
        nextCharacter = ' ';
    });

    return compressedVector;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(const std::vector<std::pair<uint8_t, uint8_t>>& compressedVector) {
    std::array<std::array<uint8_t, width>, height> decompresedArray;
    auto it = decompresedArray.begin();
    auto positionInArray = 0;

    std::for_each(compressedVector.cbegin(), compressedVector.cend(), [&](const auto& element) mutable {
        std::fill_n(it->begin() + positionInArray, element.second, element.first);
        if(positionInArray == width) {
            ++it;
            positionInArray = 0;
        } 
        positionInArray += element.second;
    });

    return decompresedArray;
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
