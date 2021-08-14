#include "compression.hpp"
#include <algorithm>
#include <array>
#include <utility>
#include <vector>

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, width>, height>& arr) {
    std::vector<std::pair<uint8_t, uint8_t>> vec;
    vec.reserve(width * height);

    std::for_each(arr.cbegin(), arr.cend(), [&vec](const auto& row) {
        auto lastValue = row.at(0);
        int counter = 0;
        for (auto pixelIt = row.cbegin(); pixelIt != row.cend(); ++pixelIt) {
            if (lastValue != *pixelIt) {
                vec.emplace_back(lastValue, counter);
                counter = 1;
                lastValue = *pixelIt;
            } else {
                ++counter;
            }
            if (pixelIt + 1 == row.cend()) {
                vec.emplace_back(lastValue, counter);
            }
    } });
    vec.shrink_to_fit();
    return vec;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(const std::vector<std::pair<uint8_t, uint8_t>>& vec) {
    std::array<std::array<uint8_t, width>, height> arr;
    std::generate(arr.front().begin(), arr.back().end(), [&vec, it = vec.cbegin(), counter = 0, pixel = 0]() mutable {
        if (counter == 0) {
            counter = it->second;
            pixel = it->first;
            ++it;
        }
        --counter;
        return pixel;
    });
    return arr;
}
