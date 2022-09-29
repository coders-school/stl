#include <map>

#include "vowel.hpp"

void removeVowels(std::vector<std::string>& words) {
    std::string str;
    str.reserve(128);
    std::map<char, bool> vowels{
        {'A', true},
        {'E', true},
        {'I', true},
        {'O', true},
        {'U', true},
        {'Y', true},
    };
    for (auto& word : words) {
        for (const char& c : word) {
            if (vowels.find(static_cast<char>(toupper(c)))->second) {
                continue;
            }
            str.push_back(c);
        }
        word = str;
        str.clear();
    }
}
