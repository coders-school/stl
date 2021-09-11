#include "compression.hpp"
#include <iostream>
#include <array>
#include <algorithm>
#include <utility>




FractionVector compressGrayscale(const FractionArray& arr)
{   
    //uint8_t ActualColor;
  //  uint8_t counter;
    FractionVector result;
    result.reserve(width * height);

    for (const auto& el : arr)
    {
        uint8_t colorActual = el.front();
        auto counter = 0;
        for (auto it = el.cbegin(); it != el.cend(); it++)
        {
            if (colorActual != *it)
            {
                result.push_back(std::make_pair(colorActual, counter));
                colorActual = *it;
                counter = 1;
            }
            else{
                counter++;
            }
            if(it + 1== el.cend())
            {
                result.push_back(std::make_pair(colorActual, counter));
            }
        }
        
    }
    result.shrink_to_fit();
    return result;
}
//     for (size_t i = 0; i < height; i++)
//     {
//         if (i > 0 )
//         {
//             result.push_back(std::make_pair(ActualColor, counter));
//             counter = 0;
//         }
//         for (size_t j = 0; j < width; j++)
//         {
//             if (j == 0)
//             {
//                 ActualColor = arr[i][j];
//                 counter++;
//             }
//             else
//             {
//                 if (ActualColor == arr[i][j])
//                 {
//                    counter++;
//                 }
//                 else
//                 {
//                     result.push_back(std::make_pair(ActualColor, counter));
//                     ActualColor = arr[i][j];
//                     counter = 1;
//                 }
//             }
//             if ((i == width -1 ) && (j == height -1) )
//             {
//                 result.push_back(std::make_pair(ActualColor, counter));
//             }
            
//         }
//     }
//     result.shrink_to_fit();
//     return result;
// }
// std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, width>, height> &uncompressed)
// {
//     std::vector<std::pair<uint8_t, uint8_t>> compressed;
//     compressed.reserve(width * height);
//     std::for_each(uncompressed.begin(),
//                   uncompressed.end(),
//                   [&compressed](auto row){
//                       for(auto uniqueElementIt = row.begin(); uniqueElementIt != row.end();) {
//                           auto nextUniqueElement = std::find_if(uniqueElementIt,
//                                                                 row.end(),
//                                                                 [&uniqueElementIt](auto x){ return x != *uniqueElementIt; });
//                           compressed.push_back(std::make_pair(*uniqueElementIt,
//                                                               std::count_if(uniqueElementIt, 
//                                                                             nextUniqueElement,
//                                                                             [&uniqueElementIt](auto x){ return x == *uniqueElementIt; })));
//                           uniqueElementIt = nextUniqueElement;
//                       }
//     });
//     return compressed;
// }

void printMap(const std::array<std::array<uint8_t, width>, height>& arr) {
    const uint8_t lowestChar{31};
    for (const auto& row : arr) {
        for (const auto& character : row) {
            if (character <= lowestChar) {
                std::cout << ' ';
            } else {
                std::cout << character;
            }
        }
        std::cout << '\n';
    }
}


// FractionArray decompressGrayscale(const FractionVector &compressed)
// {
//     std::array<std::array<uint8_t, width>, height> decompressed;
//     auto it = begin(decompressed)->begin();
//     std::for_each(compressed.begin(), compressed.end(), [&it](auto pair) {
//                                                                 std::fill_n(it, pair.second, pair.first);
//                                                                 it = std::next(it, pair.second); });
//     return decompressed;
// }

FractionArray decompressGrayscale(const FractionVector &compressed)
{
    FractionArray arr {};
    
    auto x = 0;
    auto y = 0;

    for (auto& row : compressed)
    {
        for (uint8_t i = 0 ; i < row.second ; i++)
        {
          arr.at(y).at(x) = row.first;
          x++;
        }
        if (x == width)
        {
            y++;
            x=0;
        }   
    }
    
    return arr;
}
