#include "vowel.hpp"

#include <algorithm>
#include <array>

bool isVowel(const char stringElement) {
    constexpr std::array<char, 12> vowels = {'a', 'e', 'o', 'i', 'u', 'y',
                                             'A', 'E', 'O', 'I', 'U', 'Y'};
    return std::find(vowels.begin(), vowels.end(), stringElement) != vowels.end();
}

void removeVowels(std::vector<std::string>& vector) {
    for (auto& el : vector) {
        el.erase(std::remove_if(el.begin(), el.end(), isVowel), el.end());
    }
}
