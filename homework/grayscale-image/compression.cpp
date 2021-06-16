#include "compression.hpp"

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale (std::array<std::array<uint8_t, width>, height> &originalBitmap)
{
    std::vector<std::pair<uint8_t, uint8_t>> compressedBitmap;
    compressedBitmap.reserve(1000);
    for (const auto &el : originalBitmap)
    {
        for(size_t i {0}; i < originalBitmap.size(); i++)
        {
            
            
        }
    }
    

    return compressedBitmap;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale (std::vector<std::pair<uint8_t, uint8_t>>){

}