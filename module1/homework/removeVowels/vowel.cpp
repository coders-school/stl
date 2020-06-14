#include "vowel.hpp"

#include <algorithm>

void removeVowels(std::vector<std::string>& words) {
    std::string vowels("aąeęiouyAĄEĘIOUY");

    for (auto& element : words) {
        for (auto vowel : vowels) {
            element.erase(std::remove(element.begin(), element.end(), vowel), element.end());
