#include "grayscale.hpp"

CompressedBitmap compressGrayscale(const Bitmap& bitmap)
{
    CompressedBitmap compressed{};

    uint8_t currCount{1};
    for(Bitmap::size_type i{0}; i < height; ++i)
    {
        for(Bitmap::size_type j{1}; j < width; ++j)
        {
            while(bitmap[i][j] == bitmap[i][j - 1] && j < width)
            {
                ++currCount;
                ++j;
            }
            compressed.emplace_back(bitmap[i][j - 1], currCount);
            currCount = 1;
        }
    }
    return compressed;
}

Bitmap decompressGrayscale(const CompressedBitmap& compressed)
{
    Bitmap bitmap{};

    //Have fun :)

    return bitmap;
}

uint8_t getGrayScale(uint8_t code)
{
    static constexpr std::array<uint8_t, 10> greyScaleChars
    { ' ', '.', ':', '-', '=', '+', '*', '#', '%', '@' };

    return greyScaleChars[code / 25.6];
}

void printMap(const Bitmap& bitmap) 
{
    for(const auto& row : bitmap)
    {
        for(const auto chCode : row)
        {
            std::cout << getGrayScale(chCode);
        }
        std::cout << '\n';
    }
}



