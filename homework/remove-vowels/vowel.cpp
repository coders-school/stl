#include "vowel.hpp"

void removeVowels(std::vector<std::string>& vowels) {
    std::regex vowel_re("a|e|i|o|u|y|A|E|I|O|U|Y");

    for (auto& it : vowels) {
        it = std::regex_replace(it, vowel_re, "");
    }
}