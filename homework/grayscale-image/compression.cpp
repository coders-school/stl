#include "compression.hpp"
#include <iostream>

/*
void printCompressedRow (std::vector<std::pair<uint8_t, uint8_t>> row)
{
    std::cout<<"Compressed row: ";
    for (auto p : row) std::cout<<"{"<<(int)p.first<<", "<<(int)p.second<<"} ";
    std::cout<<std::endl;
}
*/

std::vector<std::pair<uint8_t, uint8_t>> compressRow(std::array<uint8_t,width> row)
{
    std::vector<std::pair<uint8_t, uint8_t>> ans;
    ans.reserve(width);
    uint8_t previous_val=row[0], counter=1;
    
    for (int col=1; col<width; col++)
    {
        if (previous_val == row[col])
        {
            counter++;
        }
        else
        {
            ans.emplace_back(previous_val, counter);
            counter=1;
            previous_val = row[col];        
        }
    }
    ans.emplace_back(previous_val, counter);
    ans.shrink_to_fit();
    return ans;
}

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height> to_compress)
{
    std::vector<std::pair<uint8_t, uint8_t>> ans;
    ans.reserve(width*height);
    uint8_t previous_val;
    for (auto& row : to_compress)
    {
        auto compressed_row = compressRow(row);
        //printCompressedRow(compressed_row);
        ans.insert(std::end(ans), std::begin(compressed_row), std::end(compressed_row));
    }
    ans.shrink_to_fit();
    return ans;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale (std::vector<std::pair<uint8_t, uint8_t>> to_decompress)
{
    std::array<std::array<uint8_t, width>, height> ans;
    int row, col, counter=0;

    for (auto& pair : to_decompress)
        for (int i=0; i<pair.second; i++)
        {
            row = counter/height; //only integer part is saved;
            col = counter % width;
            ans[row][col] = pair.first;
            counter++;
        }
    return ans;
}
