#include "compression.hpp"
#include <algorithm>

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, width>, height>& pgmImage) {
    std::vector<std::pair<uint8_t, uint8_t>> compressedPGM;
     std::for_each(pgmImage.begin(), pgmImage.end(),[&compressedPGM](auto& PixelRow){
                    int itCompressedPGM = 0;
                    for(auto itPixelRow = PixelRow.begin(); itPixelRow != PixelRow.end();) {
                        compressedPGM.push_back(std::make_pair(*itPixelRow, 
                                                                std::count_if(itPixelRow, PixelRow.end(), 
                                                                [&itPixelRow](auto& pixel){return pixel == *itPixelRow;})));
                        itPixelRow += compressedPGM[itCompressedPGM].second;
                        itCompressedPGM++;
                    }
    });
    return compressedPGM;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(const std::vector<std::pair<uint8_t, uint8_t>>& compressedPgmImage) {
    std::array<std::array<uint8_t, width>, height> pgmImage;
    auto itPixelPair = compressedPgmImage.begin();
    for (auto& pixelRow : pgmImage) {
        auto itPixelRow = pixelRow.begin();
        while (itPixelRow != pixelRow.end()) {
            std::fill(itPixelRow, itPixelRow + (*itPixelPair).second, (*itPixelPair).first);
            std::advance(itPixelRow, (*itPixelPair).second);
            itPixelPair++;
        }
    }

    return pgmImage;
}