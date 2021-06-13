#include "compression.hpp"


std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height> bitMap)
{
    std::vector<std::pair<uint8_t, uint8_t>> tmpCompVec;
    tmpCompVec.reserve(width * height);

    uint8_t lastPixel;
    int repCounter = 0;

    for (auto &pixelLine : bitMap)
    {
        repCounter = 0;
        lastPixel = pixelLine.front();

        for (auto it = pixelLine.begin(); it != pixelLine.end(); ++it)
        {
            if ((*it != lastPixel) || (it == std::prev(pixelLine.end())))
            {
                if (it == std::prev(pixelLine.end()))
                {
                    repCounter++;
                };
                tmpCompVec.emplace_back(std::make_pair(lastPixel, (repCounter)));
                lastPixel = *it;
                repCounter = 1;
            }
            else
            {
                repCounter++;
            };
        };
    };
    tmpCompVec.shrink_to_fit();
    return tmpCompVec;
};


 std::array<std::array<uint8_t, width>, height> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>> vectorData){ 
  std::array<std::array<uint8_t, width>, height> bitmap;
  size_t rowCounter = 0;
  size_t columnCounter = 0;

  for (const auto& pair : vectorData) {
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

    return bitmap;
}
 
