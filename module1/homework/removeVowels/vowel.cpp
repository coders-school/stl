
#include "vowel.hpp"
#include <iostream>
#include <regex>

void removeVowels(std::vector<std::string>& input_vector) {
    std::regex vowels("[aeiouyAEIOUY]");

    for (std::string& element : input_vector) {
        element = regex_replace(element, vowels, "");
    }
}
