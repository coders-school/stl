#include "compression.hpp"

#include <iostream>
#include <algorithm>

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height> &compress_array)
{

    std::vector<std::pair<uint8_t, uint8_t>> vec;
    vec.reserve(width * height);

    std::for_each(compress_array.cbegin(), compress_array.cend(), [&vec](auto el)
                  {
                      uint8_t tmp = el.front();
                      uint8_t count = 0;

                      for (auto j = el.cbegin(); j < el.cend(); j++)
                      {
                          if (tmp != *j)
                          {
                              vec.push_back(std::make_pair(tmp, count));
                              tmp = *j;
                              count = 1;
                          }
                          else
                          {
                              count++;
                          }
                          if (j + 1 == el.cend())
                          {
                              vec.push_back(std::make_pair(tmp, count));
                          }
                      }
                  });
    vec.shrink_to_fit();
    return vec;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>> &decompress)
{
    std::array<std::array<uint8_t, width>, height> arr;
    std::generate(arr.front().begin(), arr.back().end(), [&, i = 0, pair = decompress.begin(), el = 0]() mutable
                  {
                    //   if (i == 0)
                    //   {
                    //       i = pair->second;
                    //       el = pair->first;
                    //       ++pair;
                    //   }
                    //   --i;
                    //   return el;
                    if (i == pair->second)
                    {
                        i = 0;
                        pair ++;
                    }
                    i++;
                    return pair->first;

                  });
        return arr;
}
