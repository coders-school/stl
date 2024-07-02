#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <algorithm>
#include <stdint.h>
#include "compressGrayscale.hpp"


/*
3a
Napisz funkcję compressGrayscale(). Powinna ona przyjąć jeden argument typu std::array<std::array<uint8_t, 240>, 160> określający rozkład odcieni szarości na obrazku 2D (który w dalszej części nazywać będziemy bitmapą) i zwróci std::vector<std::pair<uint8_t, uint8_t>> zawierający skompresowaną bitmapę.

Kompresja powinna przebiegać w następujący sposób:

    Bitmapę rysujemy od górnego lewego rogu przechodząc w prawo, następnie poziom niżej.
    Jeżeli obok siebie występuje ten sam kolor więcej niż 1 raz, funkcja powinna wrzucić do std::vector wartość tego koloru (liczba z przedziału 0 – 255) jako pierwszy element pary oraz ilość jego powtórzeń jako drugi element pary.
    Jeżeli obok siebie występują różne odcienie to funkcja powinna wypełnić std::vector wartością odcienia oraz liczbą wystąpień równą 1 (w tym przypadku pogarszamy optymalizację, gdyż przechowujemy 2x tyle danych, jednak najczęściej te same kolory są położone obok siebie).

3b
Napisz funkcję decompressGrayscale(), która zdekompresuje obrazek skompresowany w zadaniu 3a za pomocą funkcji compressGrayscale().

Jako argument funkcja decompressGrayscale() przyjmie std::vector<std::pair<uint8_t, uint8_t>> natomiast zwróci std::array<std::array<uint8_t, 240>, 160> i przeprowadzi operacje mające na celu rekonstrukcję pierwotnego formatu bitmapy.
*/


void print_array(const std::array<std::array<uint8_t, width >, height> & arr)
{
    for(int row = 0; row < height; ++row)
    {
        for(int col = 0; col < width; ++col)
        {
            std::cout << arr[row][col] << " " ;
        }
        std::cout<< '\n';
    }
    std::cout<< '\n';
}

void print_vector(const std::vector<std::pair<uint8_t, uint8_t>> & vec)
{
    for (int i = 0; i < vec.size(); ++i)
        std::cout << "{" << vec[i].first << ", " << vec[i].second << "}" << ' ' ;
    std::cout << '\n';
}


std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, width>, height> &arr)
{
    std::vector<std::pair<uint8_t, uint8_t>> compressed_bitmap;
    int counter = 0;
    uint8_t pair_buffer=arr[0][0];

    for(int row = 0; row < height; ++row)
    {
        counter = 0; // when move to next row
        pair_buffer = arr[row][0]; // set to the first element in the row
        for(int col = 0; col < width; ++col)
        {
            if (pair_buffer==arr[row][col])
            {
                counter++;

            }
            else
            {
                compressed_bitmap.push_back(std::make_pair(pair_buffer, counter));
                counter = 1;
                pair_buffer = arr[row][col];
            }

        }
        compressed_bitmap.push_back(std::make_pair(pair_buffer, counter));
    }


    return compressed_bitmap;
}


std::array<std::array<uint8_t, width>, height> decompressGrayscale(const std::vector<std::pair<uint8_t, uint8_t>>& vec)
{
    std::array<std::array<uint8_t, width>, height> arr;
    int row = 0;
    int counter = 0;

    for (const auto &el : vec)
    {
        if (counter >= width)
        {
            row++;
            counter = 0;
        }

        for (int col = counter; col < el.second + counter; ++col)
        {
            arr[row][col] = el.first;

        }
        counter += el.second;

    }

    return arr;
}

int main()
{
    // 3a
    std::array<std::array<uint8_t, width>, height> input {  0, 0, 0, 1, 1, 2, 3, 0, 0, 0,
                                                            0, 0, 4, 4, 4, 1, 1, 1, 1, 1,
                                                            2, 2, 2, 2, 2, 1, 2, 2, 2, 2 };

    std::vector<std::pair<uint8_t, uint8_t>> output = compressGrayscale(input);

    print_array(input);
    print_vector(output);
    std::cout<< '\n';

    // 3b
    std::array<std::array<uint8_t, width>, height> output2 = decompressGrayscale(output);
    print_array(output2);


    return 0;
}
