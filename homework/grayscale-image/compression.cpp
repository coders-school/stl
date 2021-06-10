#include "compression.hpp"

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height> arr) {
    std::vector<std::pair<uint8_t, uint8_t>> vec;
    uint8_t color = 0;
    uint8_t lastcolor = 0;
    // sameColor counts how many neighbouring pixels have the same color 
    unsigned int sameColor = 0; 
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (x == 0) {
                lastcolor = arr[x][y];
                sameColor = 1;
            }
            else { 
                color = arr[x][y];
                if (color == lastcolor) {
                    sameColor++;
                    

                }
                else {
                    vec.push_back(std::make_pair(lastcolor, sameColor));
                    lastcolor = color;
                    sameColor = 1;
                }
            }

        }
    }
    
    return vec;
}
std::array<std::array<uint8_t, width>, height> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>>) {
    std::array<std::array<uint8_t, width>, height> temp;
    return temp;
}

void printCompressed(std::vector<std::pair<uint8_t, uint8_t>> vec) {
    for(auto& it : vec) {
        std::cout << '{' << static_cast<int>(it.first) << ',' << static_cast<int>(it.second) << "} ";
    }
    std::cout << '\n';
}

