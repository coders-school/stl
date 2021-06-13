#include "vowel.hpp"
#include <algorithm>

void removeVowels(std::vector<std::string>& words){
    const std::string vowels = "aeiouyAEIOUY";
    for(auto &el : words){
        for(auto &c : vowels){
           el.erase(std::remove(el.begin(), el.end(), c), el.end());
        }
    }
}