#include "vowel.hpp"

#include <algorithm>
#include <cctype>

bool isVowels(unsigned char c) {
    c = std::tolower(c);

    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y') {
        return true;
    }

    return false;
}

void removeVowels(std::vector<std::string>& collection) {
    for (auto& str : collection) {
        auto it = std::remove_if(str.begin(), str.end(),
                                 [](unsigned char c) { return isVowels(c); });

        str.erase(it, str.end());
    }
}
