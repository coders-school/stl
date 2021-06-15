#include "compression.hpp"

std::vector<std::pair<uint8_t, uint8_t>>compressGrayscale
    (std::array<std::array<uint8_t, width>, height> ar){
        std::vector<std::pair<uint8_t, uint8_t>>toReturn;
        std::pair<uint8_t, uint8_t>temp;
        for(int i = 0; i < ar.size(); ++i){
            for(int j = 0; j < ar[i].size(); ++j){
                temp.first = ar[i][j];
                temp.second = 1;
                while (temp.first == ar[i][j+1] && (j+1) < ar[i].size()){
                    ++j;
                    ++temp.second;
                }
                toReturn.push_back(temp);
            }
        }
        return toReturn;
    }


std::array<std::array<uint8_t, width>, height>decompressGrayscale(
    std::vector<std::pair<uint8_t,uint8_t>>v) {
        std::array<std::array<uint8_t, width>, height> toReturn;
        
        int w = 0;
        int h = 0;
        for(const auto &item : v){
            int count = item.second;
            while (count > 0){
                toReturn[h][w] = item.first;
                w++;
                count--;
                if(w == width){
                    w = 0;
                    h++;
                }
            }
        }
        return toReturn;
    }
    
    