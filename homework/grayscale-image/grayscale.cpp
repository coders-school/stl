#include "grayscale.hpp"

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height> array_1);
{
    std::vector<std::pair<uint8_t, uint8_t>>compres_vec;
    unit_8 p = 0;
    int number = 0;
    p = array_1[0][0];

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (array_1[i][j] == p) {
                number++;
            } 
            else {
                compres_vec.push_back(make_pair(p,number));
                p = array_1[i][j];
                number = 1;

            }
        }
    }
    return 
}