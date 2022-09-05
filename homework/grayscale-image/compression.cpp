#include "compression.hpp"

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height> grayscale) {
    std::vector<std::pair<uint8_t, uint8_t>> compressed;

    uint8_t elementsCounter = 1;

    for (size_t row = 0; row < height; row++) {
        for (size_t col = 0; col < width; col++) {
            if ((col + 1) < width and grayscale[row][col] == grayscale[row][col + 1]) {
                elementsCounter++;
            } else {
                compressed.push_back({grayscale[row][col], elementsCounter});
                elementsCounter = 1;
            }
        }
    }

    return compressed;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>> grayscale) {
    std::array<std::array<uint8_t, width>, height> decompressed;

    size_t row = 0;
    size_t rowCounter = 0;

    for (std::pair<uint8_t, uint8_t> elements : grayscale) {
        for (size_t i = 0; i < elements.second; i++) {
            decompressed[row][rowCounter + i] = elements.first;
        }

        rowCounter += (int)elements.second;

        if (rowCounter == width) {
            rowCounter = 0;
            row++;
        }
    }

    return decompressed;
}

void printMap(std::array<std::array<uint8_t, width>, height> grayscale) {

    std::cout.width(width);

    for (size_t row = 0; row < height; row++) {
        for (size_t col = 0; col < width; col++) {
            std::cout << grayscale[row][col];
        }

        std::cout << std::endl;
    }
}
