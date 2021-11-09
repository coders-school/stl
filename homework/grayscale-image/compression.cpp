#include "compression.hpp"
#include <algorithm>
#include <utility>
#include <iterator>

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height> & bitmap)
{
    std::vector<std::pair<uint8_t, uint8_t>> compressed;
    std::for_each(bitmap.begin(), bitmap.end(), 
                [&compressed](const auto & row)
                {
                    uint8_t sign = row[0];
                    uint8_t qty{0};
                    std::for_each(row.begin(), row.end(), 
                                [&sign, &qty, &compressed, &row](const auto & elem) mutable
                                {
                                    if(sign == elem)
                                    {
                                        qty++;
                                    }
                                    if(sign != elem || &elem == std::prev(row.end()))
                                    {
                                        compressed.push_back(std::make_pair(sign, qty));
                                        sign = elem;
                                        qty = 1;
                                    }
                                }
                    );
                }
    );
    return compressed;
}


void printMap(std::array<std::array<uint8_t, width>, height> array)
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < height; j++)
        {
            uint8_t sign = array.at(i).at(j); 
            if(!std::isprint(sign)  || std::isspace(sign))
                std::cout<<' ';
            else
                std::cout<<sign;
            
        }
        std::cout<<'\n';
    }
}

void printMap(std::vector<std::pair<uint8_t, uint8_t>> bitmap)
{
    int sign{}; // the current number of characters on the line
    for(int i = 0; i < bitmap.size(); ++i)
    {  
        auto pair = bitmap[i];
        for(int j = 0; j < pair.second; j++)
        {
            sign++;
            if(!std::isprint(pair.first)  || std::isspace(pair.first))
                std::cout<<(int)pair.first<<' ';
            else
                std::cout<<(int)pair.first;

            if(sign == width )
            {
                std::cout<<'\n';
                sign=0;
            }
            
        }
    }
    std::cout<<'\n';
}


std::array<std::array<uint8_t, width>, height> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>> vector)
{
    std::array<std::array<uint8_t, width>, height> decompressed;
    uint8_t row{};
    uint8_t column{};

    std::vector<uint8_t> temp;
    std::for_each(vector.begin(), vector.end(), 
            [&column, &decompressed, &row, &temp](const auto & pair) mutable
            {
                std::fill_n(std::back_inserter(temp), pair.second, pair.first);
                column += pair.second;
                if(column == width)
                {
                    std::copy(temp.begin(), temp.end(), decompressed[row].begin());
                    temp.clear();
                    row++;
                    column = 0;
                }
            }
    );
    return decompressed;
}