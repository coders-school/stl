#include "compression.hpp"
#include <algorithm>
#include <iostream>

compressedImage compressGrayscale(const Image& imgToCompress) {
    compressedImage compressedImg;
    compressedImg.reserve(width * height);

    std::for_each(imgToCompress.begin(), imgToCompress.end(), [&compressedImg](const auto& row) {
        uint8_t pixCount = 0;
        uint8_t storedPixVal = row.front();
        auto it1 = row.begin();
        while (it1 != row.end()) {
            auto it2 = std::find_if(it1, row.end(),
                                    [&storedPixVal](const auto currentPixVal) { return storedPixVal != currentPixVal; });
            compressedImg.push_back(std::make_pair(storedPixVal, std::distance(it1, it2)));
            it1 = it2;
            storedPixVal = *it1;
        }
    });

    compressedImg.shrink_to_fit();
    return compressedImg;
}

Image decompressGrayscale(const compressedImage& imgToDecompress) {
    Image decompressedImg;
    auto it_imgToDecompress = imgToDecompress.begin();
    size_t cnt = 0;

    std::generate(decompressedImg.begin(), decompressedImg.end(), [&] {
        std::array<uint8_t, width> row;
        std::generate(row.begin(), row.end(), [&] {
            auto el = (*it_imgToDecompress).first;
            if (++cnt == (*it_imgToDecompress).second) {
                cnt = 0;
                std::advance(it_imgToDecompress, 1);
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
            if (std::iscntrl(element)) {
                std::cout << " ";
            } 
            else {
                std::cout << element;
            }
        });
        std::cout << "\n";
    });
}
