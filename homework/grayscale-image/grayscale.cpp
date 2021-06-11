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

Bitmap decompressGrayscale(const CompressedBitmap& compressed) {
    Bitmap bitmap;

    return bitmap;
}

void printMap(const Bitmap& bitmap) {

}



