#include "vowel.hpp"
#include <algorithm>
#include <iostream>
#include <string> 
#include <vector> 

std::vector<std::string> removeVowels(std::vector<std::string> &word) {
    std::vector<char> vowels{'A', 'E', 'I', 'O', 'U', 'Y', 'a', 'e', 'i', 'o', 'u', 'y'};
    for (auto& el : word) {
        for (const auto& ele : vowels) {
            el.erase(std::remove(el.begin(), el.end(), ele), el.end());
            }
    }
    return word;
}
