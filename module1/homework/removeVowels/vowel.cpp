#include "vowel.hpp"

#include <algorithm>
#include <array>

bool isVowel(const char letter) {
    constexpr int size = 12;
    constexpr std::array<char, size> vowels = {'a', 'e', 'i', 'o', 'u', 'y',
                                               'A', 'E', 'I', 'O', 'U', 'Y'};

    return std::find(vowels.begin(), vowels.end(), letter) != vowels.end();
}

void removeVowels(std::vector<std::string>& vec) {
    for (auto& sentence : vec) {
        sentence.erase(std::remove_if(sentence.begin(), sentence.end(), isVowel), sentence.end());
    }
}