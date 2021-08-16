#include "compression.hpp"

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, width>, height>& pgmImage) {
    std::vector<std::pair<uint8_t, uint8_t>> compressedPGM;
    for (auto& pixelRow : pgmImage) {
        uint8_t numberOfOccurences{1};
        uint8_t pixelGreyScale{0};
        std::array<uint8_t, width>::const_iterator it;
        for (it = pixelRow.begin(); it < pixelRow.end() - 1; it++) {
            if (*it == *(it + 1)) {
                numberOfOccurences++;
            } else {
                pixelGreyScale = *it;
                compressedPGM.push_back({pixelGreyScale, numberOfOccurences});
                numberOfOccurences = 1;
            }
        }
        pixelGreyScale = *it;
        compressedPGM.push_back({pixelGreyScale, numberOfOccurences});
        numberOfOccurences = 1;
    }
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