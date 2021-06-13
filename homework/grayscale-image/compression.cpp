#include "compression.hpp"

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, height>, width>& bitMap){
    std::vector<std::pair<uint8_t, uint8_t>> compress;

    for(auto el:bitMap){
        int counter = 1;
        for(size_t i = 0; i < el.size() - 1; ++i){
            if(el[i] == el[i+1] && i != el.size()-2){
                ++counter;
            }else if(el[i] == el[i+1] && i == el.size()-2){
                ++counter;
                compress.push_back(std::make_pair(el[i], counter));
                counter = 1;
            }
            else{
                compress.push_back(std::make_pair(el[i], counter));
                counter = 1;
                if(i == el.size()-2){
                    compress.push_back(std::make_pair(el[i+1], counter));
                }
            }
        }
    }

    return compress;
}

std::array<std::array<uint8_t, height>, width> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>>& compress){
    std::array<std::array<uint8_t, height>, width> decompress;

    size_t j = 0;
    size_t k = 0;

    for(auto el:compress){
        for(size_t i = 0; i < el.second; ++i){
            decompress[j][k] = el.first;
            ++k;
        }
        if(k % width == 0){
            ++j;
            k = 0;
        }
    }

    return decompress;
}