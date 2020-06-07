#include "vowel.hpp"

#include <algorithm>

std::vector<std::string>& removeVowels(std::vector<std::string>& vec) {
    std::string vow("aeiouyAEIOUY");

    for(auto& string : vec) {
        for(const auto& letter : vow) {
            string.erase(std::remove(string.begin(), string.end(), letter), string.end());
        }
    }

    return vec;
}
