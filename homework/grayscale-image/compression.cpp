#include "compression.hpp"

compressedImage compressGrayscale(const image& image) {
    compressedImage result;
    for (const auto& imageLine : image) {
        pixelType lastPixelColor;
        for (bool startLine = true; const auto& pixelColor : imageLine) {
            if (pixelColor != lastPixelColor || startLine) {
                result.emplace_back(pixelColor, 1u);
                lastPixelColor = pixelColor;
                startLine = false;
            } else {
                ++result.back().second;
            }
        }
    }
    return result;
}

image decompressGrayscale(const compressedImage& pack) {
    image result;
    size_t heightPos = 0u;
    size_t widthPos = 0u;
    imageLine line;
    for (const auto& part : pack) {
        for (uint8_t counter = 0u; counter < part.second; ++counter) {
            line[widthPos++] = part.first;
            if (widthPos == width) {
                widthPos = 0u;
                result[heightPos++] = line;
                if (heightPos == height) {  //will ignore more data than image size
                    return result;
                }
            }
        }
    }

    constexpr pixelType fillerPixel = '.';
    if (widthPos > 0u) {
        while (widthPos < width) {  //fill uncomplete line
            line[widthPos++] = fillerPixel;
        }
        result[heightPos++] = line;
    }
    if (heightPos < height) {
        line.fill(fillerPixel);
        while (heightPos < height) {  //fill uncomplete image
            result[heightPos++] = line;
        }
    }

    return result;
}

void printCode(pixelType code) {
    constexpr uint8_t additionalPrintRangeFrom = 127;
    if (std::isprint(code) || code >= additionalPrintRangeFrom) {
        std::cout << code;
    } else {
        std::cout << ' ';
    }
}

void printMap(const image& map) {
    for (const auto& line : map) {
        for (const auto& code : line) {
            printCode(code);
        }
        std::cout << '\n';
    }
}

void printCompresedMap(const compressedImage& compressed) {
    for (size_t widthPos = 0u; const auto& pack : compressed) {
        for (size_t counter = 0u; counter < pack.second; ++counter) {
            printCode(pack.first);
            if (++widthPos == width) {
                widthPos = 0u;
                std::cout << '\n';
            }
        }
    }
}
