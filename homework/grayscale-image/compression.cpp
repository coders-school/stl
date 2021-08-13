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

#include <iterator>
namespace{
    
enum class PrintVersion{
    FUNCTION,
    LAMBDA,
    NONE
};
constexpr auto print_version = PrintVersion::LAMBDA;

void printCode(PixelType code) {
    constexpr uint8_t additionalPrintRangeFrom = 127;
    if (std::isprint(code) || code >= additionalPrintRangeFrom) {
        std::cout << code;
    } else {
        std::cout << ' ';
    }
}

void printCode(ImageLine::const_iterator codeBegin, ImageLine::const_iterator codeEnd) {
    if (codeBegin == codeEnd) {
        return;
    }
    printCode(*codeBegin);
    printCode(std::next(codeBegin), codeEnd);
}

void printLine(Image::const_iterator lineBegin, Image::const_iterator lineEnd) {
    if (lineBegin == lineEnd) {
        return;
    }
    printCode(cbegin(*lineBegin), cend(*lineBegin));
    std::cout << '\n';
    printLine(std::next(lineBegin), lineEnd);
}

void printTimes(PixelType pixel, size_t counter, size_t limit) {
    if (counter == limit) {
        return;
    }
    printCode(pixel);
    printTimes(pixel, ++counter, limit);
}

void printCompresedMap(CompressedImage::const_iterator pairBegin, CompressedImage::const_iterator pairEnd, size_t width = 0) {
    if (pairBegin == pairEnd) {
        return;
    }
    printTimes((*pairBegin).first, 0, (*pairBegin).second);

    width += (*pairBegin).second;
    if (width == maxWidth) {
        std::cout << '\n';
        width = 0;
    }
    printCompresedMap(std::next(pairBegin), pairEnd, width);
}

}

void printMap(const Image& map) {
    printLine(cbegin(map), cend(map));
}

void printCompresedMap(const CompressedImage& compressed) {
    if constexpr (print_version == PrintVersion::FUNCTION){
        printCompresedMap(cbegin(compressed), cend(compressed));
    }else if constexpr (print_version == PrintVersion::LAMBDA){
        size_t width{};
        std::function<void(CompressedImage::const_iterator)> print = 
            [pairEnd = cend(compressed), &width, &print](auto pairBegin) {
                if (pairBegin == pairEnd) {
                    return;
                }

                size_t counter{};
                std::function<void()> printMultipleTimes = 
                    [pixel = (*pairBegin).first, limit = (*pairBegin).second, &counter, &printMultipleTimes]() {
                        if (counter == limit) {
                            return;
                        }
                        printCode(pixel);
                        ++counter;
                        printMultipleTimes();
                    };
                printMultipleTimes();

                width += (*pairBegin).second;
                if (width == maxWidth) {
                    std::cout << '\n';
                    width = 0;
                }
                print(std::next(pairBegin));
            };
        print(begin(compressed));
    }
}
