#include "vowel.hpp"
#include <algorithm>
#include <array>
bool isVowel(char c) {
    std::array<char, 12> a = {'a', 'A', 'E', 'e', 'I', 'i', 'O', 'o', 'U', 'u', 'Y', 'y'};
    return std::find(a.begin(), a.end(), c) != a.end();
}
void removeVowels(std::vector<std::string>& vec) {
    for (auto& el : vec) {
        el.erase(std::remove_if(el.begin(), el.end(), isVowel), el.end());
    }
}
