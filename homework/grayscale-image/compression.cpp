#include "compression.hpp"
#include <algorithm>

class ImageCompression_insert_iterator {
public:
    explicit ImageCompression_insert_iterator(CompressedImage& compressed)
        : container(compressed) {}

    ImageCompression_insert_iterator& operator=(PixelType value) {
        if (width == maxWidth) {
            width = 0;
        }

        if (width == 0 || container.back().first != value) {
            container.push_back(CompressPair(value, 1u));
        } else {
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

#include <iterator>

void printCode(ImageLine::const_iterator b, ImageLine::const_iterator e) {
    if (b == e) {
        return;
    }
    printCode(*b);
    printCode(std::next(b), e);
}

void printLine(Image::const_iterator b, Image::const_iterator e) {
    if (b == e) {
        return;
    }
    printCode(begin(*b), end(*b));
    std::cout << '\n';
    printLine(std::next(b), e);
}

void printMap(const Image& map) {
    printLine(begin(map), end(map));
}

void printTimes(PixelType pixel, size_t counter, size_t e) {
    if (counter == e) {
        return;
    }
    printCode(pixel);
    printTimes(pixel, ++counter, e);
}

void printCompresedMap(CompressedImage::const_iterator b, CompressedImage::const_iterator e, size_t width = 0) {
    if (b == e) {
        return;
    }
    printTimes((*b).first, 0, (*b).second);

    width += (*b).second;
    if (width == maxWidth) {
        std::cout << '\n';
        width = 0;
    }
    printCompresedMap(std::next(b), e, width);
}

void printCompresedMap(const CompressedImage& compressed) {
    printCompresedMap(cbegin(compressed), cend(compressed));
}
