#include "compression.hpp"

std::array<std::array<uint8_t, width>, height> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>> vec) {
    std::array<std::array<uint8_t, width>, height> resArr;
    
    int num1 = 0;
    int num2 = 0;
    for (auto& it : vec) {
        for (int i = 0; i < it.second; i++) {
            if (num2 > 31) {
                num1++;
                num2 = 0;
            }
            resArr[num1][num2] = it.first;
            num2++;
        }
    }
    return resArr;
}

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
