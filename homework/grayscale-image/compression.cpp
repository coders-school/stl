#include "compression.hpp"

#include <algorithm>
#include <iostream>

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, width>, height>& arr) {
    std::vector<std::pair<uint8_t, uint8_t>> vector;
    vector.reserve(width * height);
    std::for_each(arr.cbegin(), arr.cend(), [&vector](const std::array<uint8_t, width>& widthArr) {
        auto it = widthArr.cbegin();
        while (it != widthArr.cend()) {
            int count = -1;
            uint8_t numL = *it;
            it = std::find_if(it, widthArr.cend(), [&count, numL](const uint8_t numR) {
                ++count;
                return numL != numR;
            });
            if (it == widthArr.cend()) {
                count++;
            }
            vector.emplace_back(numL, count);
        }
    });
    vector.shrink_to_fit();
    return vector;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(const std::vector<std::pair<uint8_t, uint8_t>>& bitmap) {
    std::array<std::array<uint8_t, width>, height> arr{};
    auto it = arr.begin()->begin();
    std::for_each(bitmap.cbegin(), bitmap.cend(), [&arr, &it](const std::pair<uint8_t, uint8_t>& vec) {
        it = std::generate_n(it, vec.second, [&vec]() {
            return vec.first;
        });
    });
    return arr;
}

void printMap(const std::array<std::array<uint8_t, width>, height>& map) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            std::cout << static_cast<char>(map[i][j]);
        }
        std::cout << '\n';
    }
}

class Joke {
public:
    Joke(int d, int e, int f)
        : a(d),
          b(e),
          c(f) {}

private:
    int a;
    double b;
    long c;
};
