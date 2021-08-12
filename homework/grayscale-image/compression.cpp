#include "compression.hpp"
#include <algorithm>

class ImageCompression_insert_iterator {
public:
    explicit ImageCompression_insert_iterator(CompressedImage& x)
        : container(x) {}

    ImageCompression_insert_iterator& operator=(PixelType value) {
        if (width == maxWidth) {
            width = 0;
        }

        if (width == 0 || container.back().first != value) {
            container.push_back(CompressPair(value, 1u));
        }else{
            ++container.back().second;
        }
        ++width;
        return *this;
    }

    ImageCompression_insert_iterator& operator=(const ImageLine& line) {
        std::transform(cbegin(line), cend(line), *this,
                       [](PixelType pixel) {
                           return pixel;
                       });
        return *this;
    }

    ImageCompression_insert_iterator& operator*() { return *this; }
    ImageCompression_insert_iterator& operator++() { return *this; }

private:
    CompressedImage& container;
    size_t width = 0;
};

CompressedImage compressGrayscale(const Image& image) {
    CompressedImage compress;
    std::transform(cbegin(image), cend(image), ImageCompression_insert_iterator(compress),
                   [](const ImageLine& line) {
                       return line;
                   });
    return compress;
}

class ImageDecompression_insert_iterator {
public:
    explicit ImageDecompression_insert_iterator(Image& image)
        : container(image) {}

    ImageDecompression_insert_iterator& operator=(const CompressPair& pair) {
        std::generate_n(&container[height][width], pair.second,
                        [pixel = PixelType{pair.first}]() {
                            return pixel;
                        });
        width += pair.second;
        if (width == maxWidth) {
            width = 0;
            ++height;
        }
        return *this;
    }

    ImageDecompression_insert_iterator& operator*() { return *this; }
    ImageDecompression_insert_iterator& operator++() { return *this; }

private:
    Image& container;
    size_t width = 0;
    size_t height = 0;
};

Image decompressGrayscale(const CompressedImage& pack) {
    Image result;
    std::transform(cbegin(pack), cend(pack), ImageDecompression_insert_iterator(result),
                   [](const auto& pair) {
                       return pair;
                   });
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
            if (++widthPos == maxWidth) {
                widthPos = 0u;
                std::cout << '\n';
            }
        }
    }
}
