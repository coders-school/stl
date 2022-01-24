#include "compression.hpp"

#include <algorithm>
#include <iostream>
#include <iterator>

// compresses a bitmap into compressedImage format
CompressedImage compressGrayscale(const Image& bitmap)
{
    CompressedImage result;
    result.reserve(width * height);
    auto compress_row = [&result](const auto& row) {
        for (auto it = row.begin(); it != row.end();) {
            auto pixel_color = *it;
            auto repeat_count { 1 };
            //  check next element for same color occurences
            for (; ++it != row.end() && *it == pixel_color;) {
                ++repeat_count;
            }
            result.emplace_back(pixel_color, repeat_count);
        }
    };
    std::for_each(begin(bitmap), end(bitmap), compress_row);
    result.shrink_to_fit();
    return result;
}

// decompresses a compressed image into a grayscale bitmap
Image decompressGrayscale(const CompressedImage& compressed_bitmap)
{
    Image result;
    auto it_insert = result.begin()->begin();
    std::for_each(begin(compressed_bitmap),
                  end(compressed_bitmap),
                  [&](const auto& color_pair) {
                      auto color = color_pair.first;
                      auto repeat = color_pair.second;
                      std::fill(it_insert, it_insert + repeat, color);
                      std::advance(it_insert, repeat);
                  });

    return result;
}

// prints an uncompressed bitmap
void printMap(const Image& bitmap)
{
    std::for_each(begin(bitmap),
                  end(bitmap),
                  [](const auto& row) {
                      std::copy(begin(row),
                                end(row),
                                std::ostream_iterator<char>(std::cout));
                      std::cout << std::endl;
                  });
}