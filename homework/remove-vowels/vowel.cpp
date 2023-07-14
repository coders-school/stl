#include "vowel.hpp"

bool isVowel(char c) {
    c = std::tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y');
}

void removeVowels(std::vector<std::string>& vec) {
    for (auto& el : vec) {
        el.erase(remove_if(el.begin(), el.end(), isVowel), el.end());
    }
}