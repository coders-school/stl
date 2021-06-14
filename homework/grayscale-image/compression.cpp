#include "compression.hpp"

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height> arr) {
    std::vector<std::pair<uint8_t, uint8_t>> resVec;
    uint8_t numOfOcurrences;
    uint8_t prevNum;
    bool firstNum;
    for (auto& it : arr) {
        firstNum = true;
        numOfOcurrences = 1;
        for (auto& iter : it) {
            if (firstNum) {
                prevNum = iter;
                firstNum = !firstNum;

            } else if (prevNum == iter) {
                numOfOcurrences++;
            } else if (prevNum != iter) {
                resVec.push_back({prevNum, numOfOcurrences});
                prevNum = iter;
                numOfOcurrences = 1;
                
            }
        }

                resVec.push_back({prevNum, numOfOcurrences});
                
            
    }

    return resVec;
}
