#include "compression.hpp"

CompressedBitmap compressGrayscale(Bitmap bitmap)
{
    CompressedBitmap result;
    std::pair<uint8_t, uint8_t> buffer{bitmap[0][0], 0};

    for (const auto& line : bitmap)
    {
        for (const auto& pixel : line)
        {
            if (buffer.first == pixel)
            {
                buffer.second++;
                buffer.first = pixel;
            }
            else
            {
                result.push_back(buffer);
                buffer.first = pixel;
                buffer.second = 1;
            }
        }
        result.push_back(buffer);
    }
    return result;
}

Bitmap decompressGrayscale(CompressedBitmap compressedBitmap)
{
    Bitmap result;
    return result;
}
