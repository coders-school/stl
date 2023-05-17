#include "compression.hpp"
std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height> image)
{
    uint8_t pocket;
    uint8_t counter = 0;
    bool firstLoop = true;
    std::vector<std::pair<uint8_t, uint8_t>> compressedImage;
    for(std::array<uint8_t, 32> array : image)
    {
        for(uint8_t pixel : array)
        {
            if(firstLoop)
            {
                firstLoop = false;
                pocket = pixel;
                counter = 1;
                continue;
            }
            if(pocket == pixel)
            {
                counter++;
            }
            else
            {
                compressedImage.emplace_back(std::pair<uint8_t,uint8_t>({pocket,counter}));
                pocket = pixel;
                counter = 1;
            }
        }
        firstLoop = true;
        compressedImage.emplace_back(std::pair<uint8_t,uint8_t>({pocket,counter}));
    }
    return compressedImage;
}
std::array<std::array<uint8_t, width>, height> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>> compressedImage)
{
    std::array<std::array<uint8_t, width>, height> image;
    uint8_t cHeight = 0, cWidth = 0;
    for(std::pair<uint8_t,uint8_t> pair : compressedImage)
    {
        for(int i=0 ; i<static_cast<int>(pair.second);i++)
        {
            image.at(cHeight).at(cWidth++) = pair.first;
        }
        if(cWidth == width)
        {
            cHeight++;
            cWidth = 0;
        }
    }
    return image;
}

void printMap(std::array<std::array<uint8_t, width>, height>image)
{
    for(std::array<uint8_t, width> array : image)
    {
        for(uint8_t pixel : array)
        {
            std::cout<<pixel;
        }
        std::cout<<std::endl;
    }
}