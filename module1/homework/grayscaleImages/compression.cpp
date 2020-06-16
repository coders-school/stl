#include "compression.hpp"

#include <algorithm>
#include <deque>

std::vector<std::pair<uint8_t, uint8_t>> compressor(std::array<uint8_t, width> row) {
    std::vector<std::pair<uint8_t, uint8_t>> result{};
    std::for_each(begin(row), end(row), [&result](const auto pixel) {
        if (result.empty()) {
            result.emplace_back(std::pair{pixel, uint8_t{1}});
        } else {
            if (result.back().first == pixel) {
                result.rbegin()->second++;
            } else {
                result.emplace_back(std::pair{pixel, uint8_t{1}});
            }
        }
    });
    return result;
}

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height>& input) {
    std::vector<std::pair<uint8_t, uint8_t>> result{};
    std::for_each(begin(input), end(input), [&result](const auto& row) {
        auto rowCompressed = compressor(row);
        result.insert(result.end(), rowCompressed.begin(), rowCompressed.end());
    });
    return result;
}

std::array<std::array<uint8_t, width>, height>
decompressGrayscale(const std::vector<std::pair<uint8_t, uint8_t>> input) {
    std::deque<uint8_t> buffer;

    for (const auto& pixels : input)
        for (auto i = 0; i < pixels.second; ++i)
            buffer.emplace_back(pixels.first);

    std::array<std::array<uint8_t, width>, height> image{};
    for (auto& line : image)
        for (auto& pixel : line) {
            pixel = buffer.front();
            buffer.pop_front();
        }
    return image;
}
