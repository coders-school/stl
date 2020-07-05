#include "vowel.hpp"

#include <algorithm>
#include <array>
#include <iostream>

constexpr size_t vowelArraySize = 12;
constexpr std::array<char, vowelArraySize> vowels{'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U', 'y', 'Y'};

void removeVowelsFromString(std::string& str) {
    if (!str.length()) {
        return;
    }
    std::string::iterator it;
    for(size_t i = 0; i < vowelArraySize; ++i) {
        do {
            it = std::find(str.begin(), str.end(), vowels[i]);
            if (it != str.end()) {
                str.erase(it);
            }
        } while (it != str.end());
    }
}

void removeVowels(std::vector<std::string>& vector) {
    if (!vector.size()) {
        return;
    }
    for(auto& element : vector) {
        removeVowelsFromString(element);
    }
}
