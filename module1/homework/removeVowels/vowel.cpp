#include "vowel.hpp"

#include <algorithm>

std::array<char, 12> vowels = {'A', 'E', 'I', 'O', 'U', 'Y', 'a', 'e', 'i', 'o', 'u', 'y'};

void removeVowels(std::vector<std::string>& vectorOfStrings) {
    for (auto& str : vectorOfStrings) {
        auto first = str.begin();
        auto last = str.end();
        for (char vowel : vowels) {
            last = std::remove(first, last, vowel);
        }
        str.erase(last, str.end());
    }
}