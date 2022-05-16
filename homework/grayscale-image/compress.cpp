#include "compress.hpp"

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, 240>, 160> input)
{
    std::vector<std::pair<uint8_t, uint8_t>> vec;
    for (size_t i = 0; i < 160; i++)
    {
        auto start = 0;
        int count = 0;
        int val = 0;
        int tmp = 0;
        while(start < 240)
        {
            val = input[i][start];
            count++;
            while(start < 240)
            {
                start++;
                if(input[i][start] == val)
                {
                    count++;
                    if(start == 239)
                    {
                        break;
                    }
                }
                else
                {
                    vec.push_back(std::pair<uint8_t, uint8_t>{val, count});
                    break;
                }
            }
        }
        
    }
    
}