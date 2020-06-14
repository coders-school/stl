#include "compression.hpp"

#include <algorithm>
#include <iostream>

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, width>, height>& arr) {
    std::vector<std::pair<uint8_t, uint8_t>> vec;
    vec.reserve(width * height);
    uint8_t buffer;
    std::for_each(arr.begin(), arr.end(), [&vec, &buffer](auto ln) {
        buffer = ln.front();
        auto it1 = ln.begin();
        while (it1 != ln.end()) {
            auto it2 = std::find_if(it1, ln.end(), [&buffer](const auto a) { return buffer != a; });
            vec.push_back(std::make_pair(buffer, std::count(it1, it2, buffer)));
            it1 = it2;
            buffer = *it1;
        }
    });
    vec.shrink_to_fit();
    return vec;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(const std::vector<std::pair<uint8_t, uint8_t>>& vec) {
    std::array<std::array<uint8_t, width>, height> arr;

    auto it_vec = vec.begin();

    std::for_each(arr.begin(), arr.end(), [&](auto& ln) {
        auto it_ln = ln.begin();

        while (it_ln != ln.end()) {
            std::fill(it_ln, it_ln + (*it_vec).second, (*it_vec).first);
            it_ln += (*it_vec).second;
            it_vec++;
        }
    });

    return arr;
}

void printMap(std::array<std::array<uint8_t, width>, height>& bitmap) {
    for (const auto& ln : bitmap) {
        for (const auto& el : ln) {
            if (el <= ' ') {
                std::cout << ' ';
            } else {
                std::cout << el;
            }
        }
        std::cout << '\n';
    }
}
