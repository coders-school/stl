#include <algorithm>
#include <iostream>
#include "vowel.hpp"

void removeVowels(std::vector<std::string>& words) {
    const char vowels[] = {"aeiouyAEIOUY"};
    
    for(auto& word : words) {
        for(const auto& mark : vowels) {
            word.erase(std::remove(word.begin(), word.end(), mark), word.end());
        }
    }
}
