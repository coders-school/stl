#include "vowel.hpp"
#include <algorithm>
#include <string>
#include <vector>

bool isVowel(char c) {
    c = std::tolower(c);
    return (c == 'a' || c == 'e' || c == 'o' || c == 'u' || c == 'i' || c == 'y');
}

void removeVowels(std::vector<std::string>& words) {
    for (auto& a : words) {
        a.erase(std::remove_if(a.begin(), a.end(), isVowel), a.end());
    }
}