#include "vowel.hpp"
#include <algorithm>
#include <iostream>

void removeVowels(std::vector<std::string>& words) {
    const std::string vowels = "aeiouyAEIOUY";
    for (size_t i = 0; i < vowels.length(); ++i) {
        for (auto& el : words) {
            //std:: erase(words, vowels[i]); c++ 20
            el.erase(std::remove(el.begin(), el.end(), vowels[i]), el.end());
        }
    }
}