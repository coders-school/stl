#include "vowel.hpp"

#include <algorithm>
#include <string>

const std::string vowels = "AEIOUYaeiouy";

void removeVowels(std::vector<std::string>& vectorOfStrings) {
    for (auto& str : vectorOfStrings) {
        std::remove_if(str.begin(), str.end(), [](char c) {
            for (auto it = vowels.begin(); it != vowels.end(); it++) {
                if (*it == c) {
                    return true;
                }
            }
            return false;
        });
    }
}
