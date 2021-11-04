#include "compression.hpp"

std::vector<std::pair<uint8_t, uint8_t>> compressOneRow(std::array<uint8_t, width> row)
{
    uint8_t repetition = 1;
    uint8_t lastColor = row[0];
    std::vector<std::pair<uint8_t, uint8_t>> retVector;
    for(int i = 1; i < width; i++){
        if(lastColor != row[i]){   
            retVector.push_back(std::make_pair(lastColor, repetition));
            lastColor = row[i];
            repetition = 0;
        }
        repetition++;
    }
    retVector.push_back(std::make_pair(lastColor, repetition));
    return retVector;
}

compressedImage compressGrayscale(const image& picture)
{
    compressedImage pomVector;
    compressedImage retVector;
    for(auto it : picture){
    pomVector = compressOneRow(it);
    retVector.insert(retVector.end(), pomVector.begin(), pomVector.end());
    }
    return retVector;  
}

image decompressGrayscale(const compressedImage& inCompressedImage)
{
    int actualWidth = 0;
    int actualHeight = 0;
    image retImage;
    for(const auto& it : inCompressedImage){
        for(int i = 0; i < it.second; i++)
        {
            retImage[actualHeight][actualWidth] = it.first;
            actualWidth++;
        }
        if(actualWidth == width-1){
            actualWidth = 0;
            actualHeight++;
        }
    }
    return retImage;
}