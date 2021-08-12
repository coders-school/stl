#include "compression.hpp"

#include <algorithm>
class ImageCompression_insert_iterator {
public:
    explicit ImageCompression_insert_iterator(CompressedImage& x)
        : container(x) {}

    ImageCompression_insert_iterator& operator=(CompressedImage::const_reference value) {
        if (container.empty()) {
            container.push_back(value);
        } else if (container.back().first != value.first) {
            container.push_back(value);
        } else {
            container.back().second += 1;
        }
        return *this;
    }

    ImageCompression_insert_iterator& operator=(const ImageLine& line) {
        std::transform(cbegin(line), cend(line), *this,
                       [](uint8_t pixel) {
                           return std::pair<uint8_t, uint8_t>(pixel, 1u);
                       });
        return *this;
    }

    ImageCompression_insert_iterator& operator*() {
        return *this;
    }
    ImageCompression_insert_iterator& operator++() {
        return *this;
    }

private:
    CompressedImage& container;
};

CompressedImage compressGrayscale(const Image& image) {
    CompressedImage compress;
    std::transform(
        cbegin(image),
        cend(image),
        ImageCompression_insert_iterator(compress),
        [](const auto& line) {
            return line;
        });
    return compress;
}

Image decompressGrayscale(const CompressedImage& pack) {
    Image result;
    size_t heightPos = 0u;
    size_t widthPos = 0u;
    ImageLine line;
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

    constexpr PixelType fillerPixel = '.';
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

void printCode(PixelType code) {
    constexpr uint8_t additionalPrintRangeFrom = 127;
    if (std::isprint(code) || code >= additionalPrintRangeFrom) {
        std::cout << code;
    } else {
        std::cout << ' ';
    }
}

void printMap(const Image& map) {
    for (const auto& line : map) {
        for (const auto& code : line) {
            printCode(code);
        }
        std::cout << '\n';
    }
}

void printCompresedMap(const CompressedImage& compressed) {
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
