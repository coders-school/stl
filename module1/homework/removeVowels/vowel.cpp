#include "vowel.hpp"

#include <algorithm>
#include <iostream>

std::vector<std::string> removeVowels(std::vector<std::string>& vec) {
    std::vector<char> vowelVec{'a', 'e', 'i', 'o', 'u', 'y'};

    for (std::string& str : vec) {
        for (const char& vowel : vowelVec) {
            str.erase(std::remove(str.begin(), str.end(), vowel), str.end());
            str.erase(std::remove(str.begin(), str.end(), vowel - 32), str.end());
        }
    }
    return vec;
}