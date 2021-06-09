#include "compression.hpp"

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height> bitmap) {
    std::vector<std::pair<uint8_t, uint8_t>> vec {};
    vec.reserve(width * height);
    size_t counter = 1;
    for (const auto& line : bitmap) {
        for (auto it = cbegin(line); it < cend(line); ++it) {
            if (it != (cend(line) - 1) && *it == *(it + 1)) {
                counter++;
            } else {
                vec.push_back(std::make_pair(*it, counter));
                counter = 1;
            }
        }
    }
    return vec;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>> bitmap) {
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

void printMap(std::array<std::array<uint8_t, width>, height> ninja) {
    for (const auto& line : ninja) {
        for (const auto& el : line) {
            if (static_cast<int>(el) == 0) {
                std::cout << ' ';
            }
            std:: cout << el;
        } 
        std::cout << '\n';
    }
}

// Hey Mateusz! It's 3a solution. Please check it and give us feedback which is better ;)

// std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height> bitmap) {
//     std::vector<std::pair<uint8_t, uint8_t>> vec {};
//     std::vector<std::pair<uint8_t, uint8_t>> vec2 {};
//     vec.reserve(width * height);
//     for (const auto &line : bitmap) {
//         for (const auto &el : line) {
//             if (vec2.size() > 0 && vec2.back().first == el) {
//                 vec2.back().second++;
//             }
//             else {
//                 vec2.push_back(std::make_pair(el, 1));
//             }
//         }
//         std::move(cbegin(vec2), cend(vec2), std::back_inserter(vec));
//         vec2.clear();
//     }
//     return vec;
// }
