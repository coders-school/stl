#include "compression.hpp"


std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height> bitMap)
{
    std::vector<std::pair<uint8_t, uint8_t>> tmpCompVec;
    tmpCompVec.reserve(width * height);

    
    uint8_t lastPixel =0;
    int repCounter = 0;
std::for_each(bitMap.begin(),bitMap.end(), [&lastPixel,&repCounter,&tmpCompVec](auto& pixelLine)
    {
        repCounter = 0;
        lastPixel = pixelLine.front();
        size_t Counter=0;

        std::for_each(pixelLine.begin(),pixelLine.end(),[&pixelLine,&repCounter,&lastPixel,&tmpCompVec,&Counter](auto& it)
        {
            if ((it != lastPixel) || (Counter == pixelLine.size()-1))
            {
                if (Counter == pixelLine.size()-1)
                {
                    repCounter++;
                };
                tmpCompVec.emplace_back(std::make_pair(lastPixel, (repCounter)));
                lastPixel = it;
                repCounter = 1;
            }
            else
            {
                repCounter++;
            };
             Counter++;
        });
    });
    tmpCompVec.shrink_to_fit();
    return tmpCompVec;
};


 std::array<std::array<uint8_t, width>, height> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>> vectorData){ 
  std::array<std::array<uint8_t, width>, height> bitmap;
  size_t rowCounter = 0;
  size_t columnCounter = 0;


std::for_each(vectorData.begin(),vectorData.end(),[&rowCounter,&columnCounter,&bitmap](auto pair)
{
        if (rowCounter < height) {
          for (size_t pairValue = 0; pairValue < pair.second; ++pairValue) {
            bitmap[rowCounter][columnCounter] = pair.first;
              if (columnCounter < width - 1) {
                columnCounter++;
              } else {
                columnCounter = 0;
                rowCounter++;
              }
          }
        }
 }
 );
    return bitmap;
}
 
