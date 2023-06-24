#include "compression.h"

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, height>, width>& arr) {
    std::vector<std::pair<uint8_t, uint8_t>> vec;

    uint8_t var = 0;
    uint8_t count = 0;
    int counter = 0;
    std::for_each(arr.begin(), arr.end(), [&](std::array<uint8_t, height> el) {
        for (uint8_t i = 0; i < el.size(); i++) {
            count++;
            if (el[i] != el[i + 1]) {
                vec.push_back({el[i], count});
                count = 0;
            } else if (count == width) {
                vec.push_back({el[i], count});
                count = 0;
            }
        }
    });

    return vec;
}

std::array<std::array<uint8_t, 32>, 32> decompressGrayscale(const std::vector<std::pair<uint8_t, uint8_t>>& vec) {
    std::array<std::array<uint8_t, 32>, 32> arr;
    for (auto& row : arr) {
        for (auto& el : row) {
            el = 0;
        }
    }

    uint8_t arrIn = 0;
    uint8_t secInd = 0;
    for (auto& el : vec) {
        for (uint8_t i = 0; i < el.second; i++) {
            arr[arrIn][secInd] = el.first;
            secInd++;
            if (secInd == width) {
                secInd = 0;
                arrIn++;
            }
        }
    }
    return arr;
}