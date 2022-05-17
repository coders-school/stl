#include "decompress.hpp"

std::array<std::array<uint8_t, 32>, 32> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>> vec)
{
    std::array<std::array<uint8_t, 32>, 32> arr;
    int start = 0;
    int stop = 0;
    //std::vector<int> pozycje; 
    int suma = 0;
    for (size_t i = 0; i < arr.size(); i++)
    {
        while(suma <= 32)
        {
            suma += vec[stop].second;
            stop++;
        }
        std::array<uint8_t, 32> tmp;
        int poczatek = 0;
        for (int i = start; i <= stop; i++)
        {
            for (size_t j = poczatek; j < poczatek + vec[i].second; j++)
            {
                tmp[j] = vec[i].first;
            }
            poczatek = vec[i].second + 1;
        }
        suma = 0;
        
    }
    return arr;
}