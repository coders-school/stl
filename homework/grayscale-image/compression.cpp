#include "compression.hpp"

#include <algorithm>
#include <iostream>
#include <iterator>

CompressedBitmap compressGrayscale(const Bitmap& bitmap) {
    CompressedBitmap compressed(width * height, std::make_pair(0, 0));
    uint8_t counter = 0;
    uint8_t counterLine = 0;
    auto iter = begin(bitmap)->begin();
    std::transform(iter, 
                   (end(bitmap) - 1)->end(), 
                   begin(compressed), 
                   [&](auto pixel) { 
                       if (counterLine == height){
                           counterLine = 0;
                           counter = 0;
                       }
                       if (pixel != *std::prev(iter)) {
                           counter = 1;
                       } else {
                           counter++;
                       }                       
                       counterLine++;
                       iter++;
                       return std::make_pair(pixel, counter); 
                   });
    auto it = begin(compressed);
    compressed.erase(std::remove_if(begin(compressed), 
                                    end(compressed), 
                                    [&](auto ele){ 
                                        it++; 
                                        return ele.first == (*it).first && ele.second == (*it).second - 1; }), 
                     end(compressed));
    return compressed;
}

Bitmap decompressGrayscale(const CompressedBitmap& compressed) {
    uint8_t pixelsAmount = 0;
    Bitmap bitmap{};
    auto it = begin(compressed);
    std::transform(begin(bitmap)->begin(), 
                   (end(bitmap) - 1)->end(), 
                   begin(bitmap)->begin(), 
                   [&](auto pixel){ 
                       if (it->second - pixelsAmount == 0) {
                           pixelsAmount = 0;
                           it++;
                       }
                       pixelsAmount++;
                       return it->first; });
    return bitmap;
}

void printMap(const Bitmap& bitmap) {
    uint8_t pixelCounter = 1;
    Bitmap bitmapPrint{};
    std::transform(begin(bitmap)->begin(), 
                   (end(bitmap) - 1)->begin(),
                   begin(bitmapPrint)->begin(),
                   [&](auto pixel){ 
                       static_cast<char>(pixel < printable_ascii_min ||
                                           pixel > printable_ascii_max
                                           ? pixel = ' '
                                           : pixel);
                       return pixel; });
    std::copy_if(begin(bitmapPrint)->begin(), 
              (end(bitmapPrint) - 1)->end(),
              std::ostream_iterator<char>(std::cout, ""),
              [&](auto pixel){ 
                  if (pixelCounter > height) {
                      pixelCounter = 1;
                      std::cout << "\n";
                  }
                  pixelCounter++;
                  return true; } );
    std::cout << '\n';
}
