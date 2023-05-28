#include <algorithm>
#include <string>
#include <vector>
#include "vowel.hpp"

std::vector<std::string> removeVowels(std::vector<std::string>& words) {
    std::vector<char> vowels {
        'A', 'E', 'I', 'O', 'U', 'Y',
        'a', 'e', 'i', 'o', 'u', 'y'};
    for (auto& elem : words) {
        for (const auto& el : vowels) {
            elem.erase(std::remove(elem.begin(), elem.end(), el), elem.end());
        }
    }
    return words;
}