#include "grayscale.hpp"

CompressedBitmap compressGrayscale(const Bitmap& bitmap) {
    CompressedBitmap compressed{};
    compressed.reserve(width * height);
    
    uint8_t currCount{1};
    for (Bitmap::size_type i{0}; i < height; ++i) {
        for (Bitmap::size_type j{1}; j < width + 1; ++j) {
            while (bitmap[i][j] == bitmap[i][j - 1] && j < width) {
                ++currCount;
                ++j;
            }
            compressed.emplace_back(bitmap[i][j - 1], currCount);
            currCount = 1;
        }
    }
    
    compressed.shrink_to_fit(); 
    return compressed;
}

Bitmap decompressGrayscale(const CompressedBitmap& compressed) {
    Bitmap bitmap{};

    auto it = bitmap.begin();
    int count{0};
    for (const auto& [Val, N] : compressed) 
    {
        std::fill_n(it->begin() + count, N, Val);
        count += N;
        if(count >= width)
        {
            ++it;
            count = 0;
        }
    }

    return bitmap;
}

uint8_t getGrayScale(uint8_t code) {
    static constexpr int scale{255};
    static constexpr std::array<uint8_t, 10> grayScaleChars{' ', '.', ':', '-', '=', '+', '*', '#', '%', '@'};

    std::array<uint8_t, 10>::size_type index{index = code * grayScaleChars.size() / (scale + 1)};

    return grayScaleChars[index];
}

void printMap(const Bitmap& bitmap) {
    for (const auto& row : bitmap) {
        for (const auto chCode : row) {
            std::cout << getGrayScale(chCode);
        }
        std::cout << '\n';
    }
}
