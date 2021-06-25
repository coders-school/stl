#include "compression.hpp"

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height> bitmap)
{
    std::vector<std::pair<uint8_t, uint8_t>> compressed;
    

    for(size_t rowNumber = 0; rowNumber < height; rowNumber++)
    {
        for(size_t columnNumber = 0; columnNumber < width; columnNumber++) // column
        {
            uint8_t number = bitmap[rowNumber][columnNumber];
            uint8_t quantity{1};
            while(number == bitmap[rowNumber][columnNumber+1])
            {
                columnNumber++;
                quantity++;
                if(columnNumber == width)
                {
                    break;
                }
            }
            auto p = std::make_pair(number,quantity);
            compressed.push_back(p);
        }
    }
    //for(int i =0; i<10; i++)
     //   std::cout<<(int)compressed[i].first<<" "<<(int)compressed[i].second<<'\n';
    return compressed;
}

void printMap(std::array<std::array<uint8_t, width>, height> array)
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < height; j++)
        {
            char sign = array.at(i).at(j); 
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
                std::cout<<' ';
            else
                std::cout<<pair.first;

            if(sign == width + 1)
            {
                std::cout<<'\n';
                sign=0;
            }
            
        }
    }
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
            if(column == width +1)
            {
                column = 0;
                row++;
            }
        }
    }
    return decompressed;
} 

//***********************************************************************************************
std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale2(std::array<std::array<uint8_t, width>, height> bitmap)
{
    std::vector<std::pair<uint8_t, uint8_t>> compressed;
    
    int row{};
    for(size_t columnNumber = 0; columnNumber < width; columnNumber++) // column
    {
        uint8_t number = bitmap[row][columnNumber];
        uint8_t quantity{1};
        while(number == bitmap[row][columnNumber+1])
        {
            columnNumber++;
            quantity++;
            if(columnNumber == width)
            {
                row++;
                columnNumber=0;
            }
        }
        auto p = std::make_pair(number,quantity);
        compressed.push_back(p);
    }
    
    //for(int i =0; i<10; i++)
     //   std::cout<<(int)compressed[i].first<<" "<<(int)compressed[i].second<<'\n';
    return compressed;
}

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