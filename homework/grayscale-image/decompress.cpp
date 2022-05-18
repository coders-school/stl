#include "decompress.hpp"
#include "properties.hpp"

std::array<std::array<uint8_t, width>, height> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>> vec)
{
    std::array<std::array<uint8_t, width>, height> arr;
    int start = 0;
    int stop = 0;
    //std::vector<int> pozycje; 
    int suma = 0;
    for (size_t k = 0; k < arr.size(); k++)
    {
        while (suma < width)
        {
            suma += vec[stop].second;
            stop++;
        }
        std::array<uint8_t, width> tmp;
        int poczatek = 0;
        for (int i = start; i < stop; i++)
        {
            for (size_t j = poczatek; j < poczatek + vec[i].second; j++)
            {
                tmp[j] = vec[i].first;
            }
            poczatek += vec[i].second;
        }
        arr[k] = tmp;
        suma = 0;
        start = stop;
    }
    return arr;
}
