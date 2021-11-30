#include "compression.hpp"
#include <algorithm>
#include <iterator>
#include <iostream>
std::vector<std::pair<uint8_t, uint8_t>> compressOneRow(std::array<uint8_t, width> row)
{
    std::vector<std::pair<uint8_t, uint8_t>> retVec;
    uint8_t lastNum = *row.begin();
    auto start = row.begin();
    start++;
    uint8_t i = 1;
    std::for_each(start, row.end(), [&lastNum, &retVec, &i](uint8_t a) mutable
    {
        if(a != lastNum){
            retVec.push_back(std::make_pair(lastNum, i));
            i = 1;
            lastNum = a;
        }
        else {
            i++;
        }
    });
    retVec.push_back(std::make_pair(lastNum, i));
    return retVec;
}

compressedImage compressGrayscale(const image& picture)
{
    compressedImage pomVector;
    compressedImage retVector;
    std::for_each(picture.begin(), picture.end(), [&pomVector, &retVector] (auto singleRow) mutable
    {
        pomVector = compressOneRow(singleRow);
        retVector.insert(retVector.end(), pomVector.begin(), pomVector.end());
    });
    return retVector;  
}
image decompressGrayscale(const compressedImage& inCompressedImage)
{
    image retImage;
    auto it = retImage[0].begin();
    std::for_each(inCompressedImage.begin(), 
                  inCompressedImage.end(),
                  [&it](std::pair<uint8_t, uint8_t> a) mutable
                  {
                    it = std::fill_n(it, a.second, a.first);
                  });
    return retImage;
}