#include "compression.hpp"

std::vector<std::pair<uint8_t, uint8_t>> compressOneLine(const std::array<uint8_t, width> &line)
{
    std::vector<std::pair<uint8_t, uint8_t>> vect;
    auto it1 = line.cbegin();
    auto it2 = line.cend();
    while (it1 != line.cend())
    {
        it2 = std::find_if(it1, line.cend(), [it1](auto value) { return value != *it1; });
        vect.emplace_back(*it1, std::distance(it1, it2));
        it1 = it2;
    }
    return vect;
}
std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, width>, height> &image)
{
    std::vector<std::pair<uint8_t, uint8_t>> compressedImage;
    for (auto &line : image)
    {
        auto compressedLine = compressOneLine(line);
        compressedImage.insert(compressedImage.end(), compressedLine.begin(), compressedLine.end());
    }
    return compressedImage;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>> comressedImage)
{
    std::array<std::array<uint8_t, width>, height> original;
    uint8_t carriage = 0; // max widith specified in homework <255
    uint8_t row = 0;

    auto it1 = original.front().begin();
    for (auto &el : comressedImage)
    {
        std::fill(it1, it1 + el.second, el.first);
        std::advance(it1, el.second);
    }
    return original;
}
