#include "compression.hpp"

vectorPair compressGrayscale(arrayMap map) {
    vectorPair output;
    output.reserve(width * height);
    uint8_t color = 0;
    int value = 0;
    int column = 0;

    for (const auto& mapRow : map) {
        color = mapRow.front();
        value = 0;
        column = 0;

        for (const auto& rowElement : mapRow) {
            if (rowElement != color || column == width - 1) {
                if (column == width - 1) {
                    value++;
                }
                output.emplace_back(std::make_pair(color, (value)));
                value = 1;
                color = rowElement;
            } else {
                value++;
            }
            column++;
        }
    }
    output.shrink_to_fit();

    return output;
}
arrayMap decompressGrayscale(vectorPair vectorData) {
    arrayMap bitmap;
    size_t rowCounter = 0;
    size_t columnCounter = 0;

    for (const auto& pair : vectorData) {
        if (rowCounter < height) {
            for (size_t pairValue = 0; pairValue < pair.second; ++pairValue) {
                bitmap[rowCounter][columnCounter] = pair.first;
                if (columnCounter < width - 1) {
                    columnCounter++;
                } else {
                    columnCounter = 0;
                    rowCounter++;
                }
            }
        }
    }

    return bitmap;
}
void printMap(arrayMap& map) {
    for (const auto& mapRow : map) {
        for (const auto& rowElement : mapRow) {
            if (rowElement < width + 1) {
                std::cout << " ";
            } else {
                std::cout << rowElement;
            }
        }
        std::cout << '\n';
    }
}