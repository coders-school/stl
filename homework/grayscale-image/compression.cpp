#include "compression.hpp"

std::vector<std::pair<u_int8_t, u_int8_t>> compressGrayscale(const std::array<std::array<uint8_t, width>, height>& arr) {
    std::vector<std::pair<u_int8_t, u_int8_t>> vec;

    vec.reserve(width * height);

    size_t counter = 1;

    for (const auto& row : arr) {
        for (auto it = row.cbegin(); it != row.cend(); ++it) {
            if (it != (row.cend() - 1) && *it == *(it + 1)) {
                vec.push_back(std::pair<uint8_t, uint8_t>(*it, counter));
            } else {
                counter++;
            }
        }
    }

    vec.shrink_to_fit();

    return vec;
}
