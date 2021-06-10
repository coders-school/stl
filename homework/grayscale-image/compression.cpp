#include "compression.hpp"

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, width>, height>& input) {
    std::vector<std::pair<uint8_t, uint8_t>> result;  
    bool firstTime = true;
    for (const auto& row : input) {
        for (const auto& el : row) {
            if (firstTime) {
                result.emplace_back(el, 0);
                firstTime = false;
            }
            if (el == result.back().first) {
                ++(result.back().second);
                continue;
            }
            result.emplace_back(el, 1);
        }
        firstTime = true;
    }
    return result;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(const std::vector<std::pair<uint8_t, uint8_t>>& input) {
    std::array<std::array<uint8_t, width>, height> result;
    auto it = input.begin(); 
    auto value = (*it).first;
    auto count = (*it).second;
    
    for (size_t i = 0; i < height; ++i) {
        for (size_t j = 0; j < width; ++j) {
            if (count <= 0) {
                ++it;
                value = (*it).first;
                count = (*it).second;
            }
            --count;
            result.at(i).at(j) = value;
        }
    }
    return result;
}
