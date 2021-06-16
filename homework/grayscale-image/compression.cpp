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