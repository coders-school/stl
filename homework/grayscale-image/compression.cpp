#include "compression.hpp"

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height> arr) {
    std::vector<std::pair<uint8_t, uint8_t>> vec;
    uint8_t color = 0; // color of current character
    uint8_t lastcolor = 0; // color of current character 
    unsigned int sameColorCount = 0; // sameColorCount counts how many neighbouring characters have the same color 
    // for loop to iterate through all characters in the array arr, x, y - character coordinates
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (x == 0) {
                
                lastcolor = arr[y][x];
                sameColorCount = 1;
            }
            else { 
                color = arr[y][x];

                if (color == lastcolor) {
                    sameColorCount++;
                }
                else {
                    vec.push_back(std::make_pair(lastcolor, sameColorCount));
                    lastcolor = color;
                    sameColorCount = 1;
                }
                if(x == width - 1) {
                    vec.push_back(std::make_pair(lastcolor, sameColorCount)); 
                    sameColorCount = 1;       
                }
            }

        }
    }   
    return vec;
}
std::array<std::array<uint8_t, width>, height> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>> vec) {
    uint8_t color = 0; // color of current item in vec  
    uint x = 0; // x, y - character coordinates in return array
    uint y = 0; 
    unsigned int sameColorCount = 0; // sameColorCount hold a number of characters of the same color 
    uint characterNumber = 0; 
    std::array<std::array<uint8_t, width>, height> arr;
    for(auto& pair : vec) {
        color = pair.first;
        sameColorCount = pair.second;       
        for (int i = 0; i < sameColorCount; i++) {
            x = characterNumber % width;
            y = characterNumber / width;
            arr[y][x] = color;
            characterNumber++;
        }
    }
    // for (int y = 0; y < height; y++) {
    //     for (int x = 0; x < width; x++) {
    //         std::cout << static_cast<uint32_t> (arr[y][x]) << ", ";
    //     }
    //     std::cout << '\n';
    // }
    // std::cout << '\n';
    return arr;
}

void printCompressed(std::vector<std::pair<uint8_t, uint8_t>> vec) {
    for(auto& it : vec) {
        std::cout << '{' << static_cast<int>(it.first) << ',' << static_cast<int>(it.second) << "} ";
    }
    std::cout << '\n';
}

void printMap(std::array<std::array<uint8_t, width>, height> arr) {

        for (const auto&  itarray : arr) {
            for (const auto&  it : itarray) {
                if(it < ' ') {
                    std::cout << ' ';     
                }
                else {
                    std::cout << it; 
                }
            }
            std::cout << '\n';
        } 
}

