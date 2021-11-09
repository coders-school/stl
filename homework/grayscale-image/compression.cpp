#include "compression.hpp"
#include <algorithm>
#include <utility>
#include <iterator>

//std::vector<std::pair<uint8_t, uint8_t>> compressGrayscaleSTL(std::array<std::array<uint8_t, width>, height> & bitmap)
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
    for(int i = 0; i < vector.size(); ++i)
    {
        auto pair = vector[i];
        for(int j = 0; j < pair.second; j++)
        {
            decompressed[row][column] = pair.first;
            column++; 
            if(column == width )
            {
                column = 0;
                row++;
            }
        }
    }
    return decompressed;
} 

//***********************************************************************************************

void printMap2(std::vector<std::pair<uint8_t, uint8_t>> bitmap)
{
    int sign{}; // the current number of characters on the line
    for(int i = 0; i < bitmap.size(); ++i)
    {  
        auto pair = bitmap[i];
        for(int j = 0; j < pair.second; j++)
        {
            sign++;
            if(!std::isprint(pair.first)  || std::isspace(pair.first))
                std::cout<<' ';
            else
                std::cout<<pair.first;

            if(sign == width)
            {
                std::cout<<'\n';
                sign=0;
            }
            
        }
    }
}



void printPair(std::vector<std::pair<uint8_t, uint8_t>> &bitmap)
{
    for(int i = 0; i<bitmap.size(); i++)
       std::cout<< "( "<<(int)bitmap[i].first<<" , "<<(int)bitmap[i].second<<" )"<<std::endl;
    std::cout<<std::endl;
}

void printPair(std::vector<std::pair<uint8_t, uint8_t>> &bitmap1, 
               std::vector<std::pair<uint8_t, uint8_t>> &bitmap2)
{
    std::cout<<std::boolalpha<<(bitmap1.size() == bitmap2.size() )<<std::endl;
    bool theSame{true};
    for(int i = 0; i<bitmap1.size(); i++)
    {
        std::cout<< "( "<<(int)bitmap1[i].first<<" , "<<(int)bitmap1[i].second<<" )"<<"\t\t";
        std::cout<< "( "<<(int)bitmap2[i].first<<" , "<<(int)bitmap2[i].second<<" )"<<std::endl;
    }
       
    std::cout<<std::endl;
}

bool equal(std::vector<std::pair<uint8_t, uint8_t>> &bitmap1, 
               std::vector<std::pair<uint8_t, uint8_t>> &bitmap2)
{
    std::cout<<"size(): "<<std::boolalpha<<(bitmap1.size() == bitmap2.size() )<<std::endl;
    bool theSame{true};
    for(int i = 0; i<bitmap1.size(); i++)
    {
        if(!(bitmap1[i].first==bitmap2[i].first && bitmap1[i].second == bitmap2[i].second))
        {
            std::cout<<"diffrent cointeners ";
            return false;
        }
    }
       
    std::cout<<std::endl;
    return true;
}

void whatDiffrent(std::vector<std::pair<uint8_t, uint8_t>> &bitmap1, 
               std::vector<std::pair<uint8_t, uint8_t>> &bitmap2)
{
    
    for(int i = 0; i<bitmap1.size(); i++)
    {
        if(!(bitmap1[i].first==bitmap2[i].first && bitmap1[i].second == bitmap2[i].second))
        {
            std::cout<< "( "<<(int)bitmap1[i].first<<" , "<<(int)bitmap1[i].second<<" )"<<"\t\t";
            std::cout<< "( "<<(int)bitmap2[i].first<<" , "<<(int)bitmap2[i].second<<" )"<<std::endl;
        }
    }
       
    std::cout<<std::endl;
}



std::array<std::array<uint8_t, width>, height> decompressGrayscaleSTL(std::vector<std::pair<uint8_t, uint8_t>> vector)
{
    std::array<std::array<uint8_t, width>, height> decompressed;
    uint8_t row{};
    uint8_t column{};
    for(int i = 0; i < vector.size(); ++i)
    {
        auto pair = vector[i];
        for(int j = 0; j < pair.second; j++)
        {
            decompressed[row][column] = pair.first;
            column++; 
            if(column == width )
            {
                column = 0;
                row++;
            }
        }
    }

    //std::for_each()

    return decompressed;
}