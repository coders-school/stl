#include "compression.hpp"

comprBitMap compressOneLine(const std::array<uint8_t, width> &line)
{
    std::vector<std::pair<uint8_t, uint8_t>> vect;
    vect.reserve(width);
    auto it1 = line.cbegin();
    while (it1 != line.cend())
    {
        auto it2 = std::find_if(it1, line.cend(), [it1](auto value) { return value != *it1; });
        vect.emplace_back(*it1, std::distance(it1, it2));
        it1 = it2;
    }
    vect.shrink_to_fit();
    return vect;
}
comprBitMap compressGrayscale(const bitMap&image)
{
    comprBitMap compressedImage;
    for (auto &line : image)
    {
        auto compressedLine = compressOneLine(line);
        compressedImage.insert(compressedImage.end(), compressedLine.begin(), compressedLine.end());
    }
    compressedImage.shrink_to_fit();
    return compressedImage;
}

bitMap decompressGrayscale(comprBitMap comressedImage)
{
    bitMap original;
    uint8_t carriage = 0;
    uint8_t row = 0;

    auto it1 = original.front().begin();
    for (auto &el : comressedImage)
    {
        std::fill(it1, it1 + el.second, el.first);
        std::advance(it1, el.second);
    }
    return original;
}
