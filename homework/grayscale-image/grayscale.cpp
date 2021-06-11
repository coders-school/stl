#include "grayscale.hpp"

CompressedBitmap compressGrayscale(const Bitmap& bitmap) {
     CompressedBitmap compressed;
     std::pair<int,int> pair;
 
    for (int i = 0; i < width; i++) {
        pair.first = bitmap[i][0];
        pair.second = 0;
 
        for (int j = 0; j < height; j++) {
            if (pair.first == bitmap[i][j]) {
                pair.second += 1;
                if (j == height-1) {
                    compressed.push_back(pair);
                }
            } else {
                compressed.push_back(pair);
                pair.first = bitmap[i][j];
                pair.second = 1;
            }
        }
    }
    return compressed;
}

Bitmap decompressGrayscale(const CompressedBitmap& compressed) {
    Bitmap bitmap;

    return bitmap;
}

void printMap(const Bitmap& bitmap) {

}



