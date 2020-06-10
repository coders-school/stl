#include "vowel.hpp"

#include <algorithm>
#include <array>

void removeVowels(std::vector<std::string>& vec) {
    constexpr std::array<char, 12> vowels{'a', 'e', 'i', 'o', 'u', 'y', 'A', 'E', 'I', 'O', 'U', 'Y'};

    for (auto& str : vec) {
        for (size_t i = 0; i < str.length(); i++) {
            if (std::find(vowels.begin(), vowels.end(), str[i]) != vowels.end()) {
                str.erase(i, 1);
                i -= 1;
            }
        }
    }
}