#include "compression.hpp"

#include <iostream>


void printMap(const Bitmap& bitmap){

   for(const auto row : bitmap){
      for(const auto pixel : row){
            std::cout<<pixel;
      }
      std::cout<<'\n';  
   }
   std::for_each(bitmap.begin(), bitmap.end(),
                [](const auto row){
                    std::for_each(row.begin(), row.end(),
                            [](const auto pixel){
                            std::cout<<pixel;
                            });
                    std::cout<<'\n';
                });
}

CompressedBitmap compressLine(const std::array<uint8_t, width>& row){

   CompressedBitmap result;
   result.reserve(width);
   std::pair<uint8_t, uint8_t> buffer{row[0], 0};

   for(const auto pixel : row){

      if(buffer.first == pixel){
         buffer.second++;
      }else{
         result.push_back(buffer);
         buffer.first = pixel;
         buffer.second = 1;
      }
   }

   result.push_back(buffer);
   result.shrink_to_fit();

   return result;
}

CompressedBitmap compressGrayscale(const Bitmap& bitmap){

   CompressedBitmap result;
   result.reserve(height*width);
   CompressedBitmap tmp;
   tmp.reserve(width);

   for(const auto row : bitmap){
      tmp = compressLine(row);
      result.insert(result.end(), tmp.begin(), tmp.end());
   }
   result.shrink_to_fit();

   return result;
}
Bitmap decompressGrayscale(const CompressedBitmap& compresed){

   Bitmap result;
   auto it = result[0].begin();

   for(const auto& grup : compresed){
      it = std::fill_n(it, grup.second, grup.first);
   }

   return result;
}
 
