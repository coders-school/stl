#include "compression.hpp"
#include <algorithm>
#include <iterator>
std::vector<std::pair<uint8_t, uint8_t>> compressOneRow(std::array<uint8_t, width> row)
{
    std::vector<std::pair<uint8_t, uint8_t>> retVec;
    auto it = row.begin();
    uint8_t lastNum = *row.begin();
    while(it != row.end())
    {
        auto resultIt = std::find_if(it, row.end(), [lastNum](uint8_t a){return a != lastNum;});
        retVec.push_back(std::make_pair(lastNum, std::distance(it, resultIt)));
        it = resultIt;
        lastNum = *resultIt;
    }
    return retVec;
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
    image retImage;
    int actualWidth = 0;
    int actualHeight = 0;
    std::for_each(inCompressedImage.begin(), 
                  inCompressedImage.end(),
                  [&retImage, &actualHeight, &actualWidth](std::pair<uint8_t, uint8_t> a) mutable{
                    for(int i = 0; i < a.second; i++){
                        retImage[actualHeight][actualWidth] = a.first;
                        actualWidth++;
                    }
                    if(actualWidth == width-1){
                        actualWidth = 0;
                        actualHeight++;
                    }
                  });
    return retImage;
}