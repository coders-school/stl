#include "compression.hpp"

#include <algorithm>
#include <iostream>

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, width>, height>& dataToCompress) {
    std::vector<std::pair<uint8_t, uint8_t>> vecCompressed;
    vecCompressed.reserve(width * height);
    std::for_each(dataToCompress.begin(), dataToCompress.end(), [&vecCompressed](auto entry) {
        uint8_t currValue = entry.front();
        auto it_first = entry.begin();
        while (it_first != entry.end()) {
            auto it_last = std::find_if(it_first, entry.end(), [&currValue](const auto value) {
                return currValue != value;
            });
            vecCompressed.push_back({currValue, std::count(it_first, it_last, currValue)});
            it_first = it_last;
            currValue = *it_last;
        }
    });

    vecCompressed.shrink_to_fit();

    return vecCompressed;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(const std::vector<std::pair<uint8_t, uint8_t>>& dataTodecompress) {
    std::array<std::array<uint8_t, width>, height> arrayDecompressed;
    auto it = arrayDecompressed.front().begin();
    std::for_each(dataTodecompress.begin(), dataTodecompress.end(), [it](const auto& pair) mutable {
        it = std::fill_n(it, pair.second, pair.first);
    });
    return arrayDecompressed;
}

void printMap(const std::array<std::array<uint8_t, height>, width>& mapToPrint) {
    for (const auto& column : mapToPrint) {
        for (const auto& rowValue : column) {
            if (rowValue > ASCIIspace) {
                std::cout << rowValue;
            } else {
                std::cout << ASCIIspace;
            }
        }
        std::cout << '\n';
    }
}
