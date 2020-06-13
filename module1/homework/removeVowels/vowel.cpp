#include "vowel.hpp"

#include <algorithm>
#include <iostream>

static bool isVowel(char c) {
    std::string vowels = "aeiouyAEIOUY";
    
    return std::find(std::begin(vowels), std::end(vowels), c) != std::end(vowels);
}

void removeVowels(std::vector<std::string>& vec) {
    for (auto& s : vec) {
        s.erase(std::remove_if(s.begin(), s.end(), isVowel), s.end());
    }
}
