#include "compression.hpp"

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height>& pgmImage) {
    std::vector<std::pair<uint8_t, uint8_t>> compressedPGM;
    for (auto pixelRow : pgmImage) {
        auto it = pixelRow.begin();
        uint8_t numberOfOccurences{1};
        uint8_t pixelGreyScale{0};
        while (it != pixelRow.end()) {
            if ((*it) == *(it + 1)) {
                numberOfOccurences++;
                it++;
            } else {
                pixelGreyScale = *it;
                compressedPGM.push_back({pixelGreyScale, numberOfOccurences});
                numberOfOccurences = 1;
                it++;
            }
        }
    }
    return compressedPGM;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>>& compressedPgmImage) {
    std::array<std::array<uint8_t, width>, height> pgmImage;
    return pgmImage;
}