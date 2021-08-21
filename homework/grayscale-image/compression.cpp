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
    int itPixelRow = 0;
    auto itPixel = pgmImage[itPixelRow].begin();
    for_each(compressedPgmImage.begin(),compressedPgmImage.end(),[&itPixelRow, &itPixel, &pgmImage](const auto& pixelPair){
        std::fill_n(itPixel, pixelPair.second, pixelPair.first);
        std::advance(itPixel, pixelPair.second);
        if (itPixel == pgmImage[itPixelRow].end() -1){
            ++itPixelRow;
            itPixel = pgmImage[itPixelRow].begin();
        }
    });
    return pgmImage;
}