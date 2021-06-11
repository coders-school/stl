#include "vowel.hpp"
#include <algorithm>
#include <iostream>
#include <string>


void removeVowels(std::vector<std::string>& words) {
    const std::string vowels = "aeiouyAEIOUY";
    for (int i = 0; i < vowels.length(); i++) {
        for (auto& el : words) {
            el.erase(std::remove(el.begin(), el.end(), vowels[i]), el.end());
        }
    }
}
