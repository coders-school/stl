#include "vowel.hpp"

#include <algorithm>

std::vector<std::string>& removeVowels(std::vector<std::string>& vec) {
    std::string vow("aeiouyAEIOUY");

    for(auto& string : vec) {
        for(auto& letter : vow) {
            if(std::find(string.begin(), string.end(), letter) != string.end()) {
                string.erase(std::remove(string.begin(), string.end(), letter), string.end());
            }
        }
    }

    return vec;
}
