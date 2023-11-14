#include "vowel.hpp"
#include <algorithm>

bool isVowel(const char& ch) {
    char c = static_cast<char>(std::tolower(ch));
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y')
        return true;
    return false;
}

void removeVowels(std::vector<std::string>& vec) {
    for (auto& e : vec)
        e.erase(std::remove_if(e.begin(), e.end(), isVowel), e.end());
}
