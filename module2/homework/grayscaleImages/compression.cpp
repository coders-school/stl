#include "compression.hpp"

vectorPair compressGrayscale(arrayMap map) {
    vectorPair output;
    std::vector<uint8_t> v(width * height);

    for (const auto& mapRow : map) {
        for (auto color = mapRow.begin(); color != mapRow.end();) {
            auto nextColor = std::adjacent_find(color, mapRow.end(), std::not_equal_to<int>{});

            if (nextColor != mapRow.end()) {
                nextColor++;
            }
            output.emplace_back(*color, std::distance(color, nextColor));
            color = nextColor;
        }
    }

    return output;
}
arrayMap decompressGrayscale(vectorPair vectorData) {
    arrayMap bitmap;
    auto it = bitmap[0].begin();

    for (auto [color, count] : vectorData) {
        std::fill_n(it, count, color);
        std::advance(it, count);
    }

    return bitmap;
}
void printMap(arrayMap& map) {
    for (const auto& mapRow : map) {
        for (const auto& rowElement : mapRow) {
            if (rowElement < width + 1) {
                std::cout << " ";
            } else {
                std::cout << rowElement;
            }
        }
        std::cout << '\n';
    }
}