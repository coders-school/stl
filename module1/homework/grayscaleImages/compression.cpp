#include "compression.hpp"

CompressedBitmap compressLine(std::array<uint8_t, 10> arr)
{
    std::pair<uint8_t, uint8_t> p{arr[0], 0};

    CompressedBitmap bmp;

    for (const auto& i : arr)
    {
        if (p.first == i)
        {
            p.second++;
        }
        else
        {
            bmp.push_back(p);
            p.first = i;
            p.second = 1;
        }
    }

    bmp.push_back(p);
    return bmp;
}




CompressedBitmap compressGrayscale(Bitmap bitmap)
{
    CompressedBitmap result;
    return result;
}

Bitmap decompressGrayscale(CompressedBitmap compressedBitmap)
{
    Bitmap result;
    return result;
}
