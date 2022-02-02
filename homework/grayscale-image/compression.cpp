#include "compression.hpp"
#include <iostream>
#include <algorithm>


void printCompressedRow (std::vector<std::pair<uint8_t, uint8_t>> row)
{
    std::cout<<"Compressed row: ";
    for (auto p : row) std::cout<<"{"<<(int)p.first<<", "<<(int)p.second<<"} ";
    std::cout<<std::endl;
}

std::vector<std::pair<uint8_t, uint8_t>> compressRow(std::array<uint8_t,width> row)
{
    std::vector<std::pair<uint8_t, uint8_t>> ans;
    ans.reserve(width);
    uint8_t previous_val=row[0];
    int counter=0;
    
    auto counter_pusher = [&ans, &previous_val, &counter](uint8_t next_val)
        {
            if (previous_val == next_val) counter++;
            else
            {
                ans.emplace_back(previous_val, counter);
                counter = 1;
                previous_val = next_val;
            }
        };

    std::for_each(begin(row), end(row), counter_pusher);
    ans.emplace_back(previous_val, counter);
    ans.shrink_to_fit();
    return ans;
}

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height> to_compress)
{
    std::vector<std::pair<uint8_t, uint8_t>> ans;
    ans.reserve(width*height);
    
    std::for_each(begin(to_compress), end(to_compress), [&ans](auto& row){
            auto compressed_row = compressRow(row);
            ans.insert(end(ans), begin(compressed_row), end(compressed_row));
    });

    ans.shrink_to_fit();
    return ans;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>> to_decompress)
{
    std::array<std::array<uint8_t, width>, height> ans;
    auto it = begin(*begin(ans)); //we can use it as 1D array pointer, since memory is contigous
    std::for_each(begin(to_decompress), end(to_decompress), [&it](auto pair){it = std::ranges::fill_n(it, pair.second, pair.first);} );

    return ans;
}
