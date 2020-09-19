
#include "vowel.hpp"

#include <algorithm>
#include <array>

bool isVowel(const char letters) {
    constexpr std::array<char, 12> vowels = {'a', 'A', 'i', 'I', 'u', 'U', 'e', 'E', 'o', 'O', 'y', 'Y'};

    return std::find(vowels.begin(), vowels.end(), letters) != vowels.end();
}

void removeVowels(std::vector<std::string>& vec) {
    for (auto& el : vec) {
        el.erase(std::remove_if(el.begin(), el.end(), isVowel), el.end());
    }
}
