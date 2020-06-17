#include "compression.hpp"
#include <iostream>

void printMap(const Bitmap& bitmap)
{
    for (const auto line : bitmap)
    {
        for (const auto pixel : line)
        {
            std::cout << pixel;
        }
        std::cout << "\n";
    }
}

CompressedBitmap compressLine(const std::array<uint8_t, width>& line)
{
    CompressedBitmap result;
    result.reserve(width);
/*   some ideas....
   std::array<int, 10> arr{1,1,1,2,2,2,3,3,1,1};

auto p = std::equal_range(std::begin(arr), std::end(arr), arr.front());
 
    for ( auto i = p.first; i != p.second; ++i )
        std::cout << *i << "\n"; 
//std::cout << std::distance(p.first, p.second) << "\n";

auto q = std::equal_range(p.second, std::end(arr), *p.second);
 
    for ( auto i = q.first; i != q.second; ++i )
        std::cout << *i << "\n"; *
        */

    std::transform(std::begin(line), std::end(line),
    [&](uint8_t pixel)
    {
        if(!result.empty() and result.back().first == pixel)
        {
            result.back().second++;
        }
        else
        {
            result.push_back(std::make_pair(pixel,1));
        }
    }
    );


    result.shrink_to_fit();
    return result;
}

CompressedBitmap compressGrayscale(const Bitmap& bitmap)
{
    CompressedBitmap result;
    result.reserve(width);
    CompressedBitmap tmp;
    tmp.reserve(width);

    for (const auto& line : bitmap)
    {
        tmp = compressLine(line);
        result.insert(std::end(result), std::begin(tmp), std::end(tmp));
    }
    result.shrink_to_fit();
    return result;
}

Bitmap decompressGrayscale(const CompressedBitmap& compressedBitmap)
{
    Bitmap result;
    auto iter = std::begin(result.front());
    for (const auto& group : compressedBitmap)
    {
        iter = std::fill_n(iter, group.second, group.first);
    }
    return result;
}
