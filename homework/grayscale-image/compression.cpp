#include "compression.hpp"

vectorPicture compressGrayscale(arrayPicture& picture){
    vectorPicture compressedPicture;
    
    for(auto i = 0; i < height; i++){
        size_t pixelCounter = 1;
        for(auto j = 1; j < width; j++){
            if(picture[i][j] == picture[i][j - 1]){
                pixelCounter++;
            }
            else{
                compressedPicture.push_back(std::make_pair(picture[i][j-1],pixelCounter)); 
                pixelCounter = 1;           
            }
            if(j == width - 1){
                compressedPicture.push_back(std::make_pair(picture[i][j],pixelCounter));
            }
        }
    }
    
    return compressedPicture;
}

arrayPicture decompressGrayscale(vectorPicture& compressedPicture){
    arrayPicture picture;
    
    size_t numOfCol = 0;
    size_t numOfRow = 0;
    
    for(auto& compressedPixels: compressedPicture){
        auto valueOfPixel = compressedPixels.first;
        auto pixelCounter = compressedPixels.second;
        for(auto i = 0; i < pixelCounter; i++){
            picture[numOfRow][numOfCol] = valueOfPixel;
            numOfCol++;
        }
        if(numOfCol == width){
            numOfCol = 0;
            numOfRow++;
        }
    }

    return picture;
}