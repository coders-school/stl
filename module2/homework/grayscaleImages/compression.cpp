#include "compression.hpp"

#include <algorithm>
#include <iostream>

void printMap(const Bitmap &bitmap)
{

   for (const auto row : bitmap)
   {
      for (const auto pixel : row)
      {
         std::cout << pixel;
      }
      std::cout << '\n';
   }
   std::for_each(bitmap.begin(), bitmap.end(),
                 [](const auto row) {
                    std::for_each(row.begin(), row.end(),
                                  [](const auto pixel) {
                                     std::cout << pixel;
                                  });
                    std::cout << '\n';
                 });
}

CompressedBitmap compressLine(const Line &row)
{

   CompressedBitmap result;
   result.reserve(width);

   for (auto color = row.begin(); color != row.end();)
   {
      auto nextColor = std::adjacent_find(color, row.end(), std::not_equal_to<int>{});
      if (nextColor != row.end())
      {
         nextColor++;
      }
      result.emplace_back(*color, std::distance(color, nextColor));
      color = nextColor;
   }

   result.shrink_to_fit();

   return result;
}

CompressedBitmap compressGrayscale(const Bitmap &bitmap)
{

   CompressedBitmap result;
   result.reserve(height * width);
   CompressedBitmap tmp;
   tmp.reserve(width);

   for (const auto row : bitmap)
   {
      tmp = compressLine(row);
      result.insert(result.end(), tmp.begin(), tmp.end());
   }
   result.shrink_to_fit();

   return result;
}
Bitmap decompressGrayscale(const CompressedBitmap &compresed)
{

   Bitmap result;
   auto it = result.front()).begin();

   for (const auto &grup : compresed)
   {
      it = std::fill_n(it, grup.second, grup.first);
   }

   return result;
}
