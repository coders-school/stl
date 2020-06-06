#include "vowel.hpp"

#include <regex>

void removeVowels(std::vector<std::string>& words) {
    std::regex vowels("[AEIOUYaeiouy]");
    for (auto& str : words) {
        if (!str.empty()) {
            str = std::regex_replace(str, vowels, "");
        }
    }
}
