#include "compression.hpp"

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height>& paint) {
    std::vector<std::pair<uint8_t, uint8_t>> vec;
    for (auto n : paint) {
        int count = 1;
        for (int i = 0; i < n.size(); i++) {
            std::cout << n[i];

            if (n[i] == n[i + 1]) {
                ++count;
            } else {
                vec.push_back(std::make_pair(n[i], count));
                count = 1;
            }
        }
    }
    return vec;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>>& vec) {
    std::array<std::array<uint8_t, width>, height> arr;
    int c = 0;
    int counter = 0;
    int counter2 = 0;

    for (auto n : vec) {
        for (int a = 0; a < n.second; a++) {
            arr[c][counter2] = n.first;
            if (counter == 31) {
                counter = 0;
                c++;
            } else {
                counter++;
            }
            if (counter2 < 31) {
                counter2++;
            } else {
                counter2 = 0;
            }
        }
    }
    return arr;
}