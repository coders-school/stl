#include <algorithm>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <utility>

#include "compression.hpp"

CompressedImage compressGrayscale(const Image& decompressedImage)
{
    CompressedImage compressed;
    std::for_each(decompressedImage.cbegin(), decompressedImage.cend(),
        [&compressed](const auto& row) {
            size_t counter = 1;
            auto previous = row.front();
            std::for_each(std::next(row.cbegin()), row.cend(),
                [&counter, &previous, &compressed](const auto& el) mutable {
                    if (el == previous) {
                        counter++;
                    } else {
                        compressed.emplace_back(std::make_pair(previous, counter));
                        previous = el;
                        counter = 1;
                    }
                });
            compressed.emplace_back(std::make_pair(previous, counter));
        });
    return compressed;
}

Image decompressGrayscale(const CompressedImage& compressedImage)
{
    Image decompressedImage;
    auto tableIterator = decompressedImage[0].begin();
    std::for_each(compressedImage.cbegin(), compressedImage.cend(),
        [&tableIterator](const auto& el) mutable {
            auto [value, count] = el;
            tableIterator = std::fill_n(tableIterator, count, value);
        });
    return decompressedImage;
}

void printMap(const Image& imgMap)
{
    std::for_each(imgMap.cbegin(), imgMap.cend(), [](const auto& row) {
        std::for_each(row.cbegin(), row.cend(), [](const auto& character) {
            if (std::isprint(character)) {
                std::cout << character;
            } else {
                std::cout << ' ';
            }
        });
        std::cout << '\n';
    });
}
