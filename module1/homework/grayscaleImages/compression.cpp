#include "compression.hpp"

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, 240>, 160>& arr) {
    std::vector<std::pair<uint8_t, uint8_t>> vec;
    uint8_t counter;
    uint8_t buffer;
    for (const auto& ln : arr) {
        counter = 1;
        buffer = ln.at(0);
        for (const auto& el : ln) {
            if (buffer == el) {
                counter++;
            } else {
                vec.push_back(std::make_pair(buffer, counter));
                counter = 1;
                buffer = el;
            }
        }
        vec.push_back(std::make_pair(buffer, counter));
    }
    return vec;
}
