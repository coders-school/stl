#include "vowel.hpp"

#include <algorithm>
#include <array>
#include <iostream>
#include <string>
#include <vector>

void removeVowels(std::vector<std::string>& words) {

    for (auto &word : words) {
        std::string temp;
        for (auto it = begin(word); it != end(word); it++) {
            if (!isVowel(*it)) {
                temp.push_back(*it);
            }
        }
        word.swap(temp);
    }
}

bool isVowel(const char& c) {
    std::array<char, 12> vowels {'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U', 'y', 'Y'};

    auto search = std::find(begin(vowels), end(vowels), c);
    return search != end(vowels);
}
