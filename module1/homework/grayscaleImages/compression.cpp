#include "compression.hpp"
#include <algorithm>
#include <iostream>

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, width>, height>& imgToCompress) {
    std::vector<std::pair<uint8_t, uint8_t>> compressedImg;
 
    std::for_each(imgToCompress.begin(), imgToCompress.end(), [&compressedImg](const auto& row) {
        uint8_t pixCount = 0;
        for (auto it = row.begin(); it != row.end(); ++it) {
            if (it == row.begin() || *it == *(it - 1)) {
                ++pixCount;
            } 
            else {
                compressedImg.push_back(std::make_pair(*(it - 1), pixCount));
                pixCount = 1;
            }

            if (it == row.end() - 1) {
                compressedImg.push_back(std::make_pair(*it, pixCount));
            }
        }
    });

    return compressedImg;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(const std::vector<std::pair<uint8_t, uint8_t>>& imgToDecompress) {
    std::array<std::array<uint8_t, width>, height> decompressedImg;
    auto it_imgToDecompress = imgToDecompress.begin();
    size_t cnt = 0;

    std::generate(decompressedImg.begin(), decompressedImg.end(), [&]{
        std::array<uint8_t, width> row;
        std::generate(row.begin(), row.end(), [&]{
            auto el = (*it_imgToDecompress).first;
            if (++cnt == (*it_imgToDecompress).second) {
                cnt = 0;
                //std::next(it_imgToDecompress);
                std::advance(it_imgToDecompress, 1);
                //++it_imgToDecompress;
            }
            return el;
        });
        return row;
    });

    return decompressedImg;
}

void printMap(const std::array<std::array<uint8_t, width>, height>& bitmap) {
    std::for_each(bitmap.begin(), bitmap.end(), [](const auto& row) {
        std::for_each(row.begin(), row.end(), [](const auto& element) {
            if (element < ' ') {
                std::cout << " ";
            } 
            else {
                std::cout << element;
            }
        });
        std::cout << "\n";
    });
}
