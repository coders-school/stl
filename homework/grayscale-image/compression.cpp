#include "compression.hpp"

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, 240>, 160>& image_array) {
    std::vector<std::pair<uint8_t, uint8_t>> amount_of_gray;
    amount_of_gray.reserve(image_array.size());
    for (auto row_colors : image_array) {
        uint8_t unique = 1;
        uint8_t act_color = 256;
        for (auto color : row_colors) {
            if (color == act_color) {
                ++unique;
            }
            else {
                amount_of_gray.push_back(std::make_pair(color, unique));
            }
        }
    }
    return amount_of_gray;
}