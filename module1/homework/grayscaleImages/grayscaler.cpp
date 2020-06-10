#include "grayscaler.hpp"

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(
    std::array<std::array<uint8_t, WIDTH>, HEIGHT>& bitmap){
    
    std::vector<std::pair<uint8_t, uint8_t>> output;
    for(auto& line : bitmap){
        uint8_t counter = 1;
        uint8_t color = line.back();

        for(int i = 1; i < line.size(); i++){
            if(color == line[i]){
                counter++;
            } else {
                output.emplace_back(std::make_pair(color, counter));
                counter = 1;
                color = line[i];
            }
        }

        output.emplace_back(std::make_pair(color, counter));
    }
    
    return output;
}