#include "compression.hpp"

#include <iostream>
#include <algorithm>

void printMap(const bitmapArr& bitmap) {
    

    for (const auto& arr : bitmap) {
        for (auto el : arr) {
            if (iscntrl(el))
                std::cout << " ";
            else
                std::cout << el;
        }
        std::cout << "\n";
    }
}

grayScaleVec compressGrayscale(const bitmapArr& grayScale) {

    grayScaleVec compressed;
    compressed.reserve(width * height);

    for (const auto& row : grayScale) {
        for(auto it = row.begin(); it != row.end();){
            auto firstNotMatch = std::find_if(it, row.end(), [&it](const auto &pixel) { return pixel != *it; });
            compressed.push_back({ *it, std::distance(it, firstNotMatch) });
            it = firstNotMatch;
        }
    }

    compressed.shrink_to_fit();
    return compressed;
}

bitmapArr decompressGrayscale(const grayScaleVec& compressed) {

    bitmapArr  decompressed;
    auto it = decompressed.front().begin();

    std::for_each(compressed.begin(), compressed.end(), [&it](const auto& pair){
        it = std::fill_n(it, pair.second, pair.first);
    });

    return decompressed;
}
