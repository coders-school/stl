#include "vowel.hpp"
#include <algorithm>

void removeVowels (std::vector <std::string>& sentence) {
    const std::string vowels {"aeiouyAEIOUY"};
    for (auto &el : sentence) {
        for (auto& ch : vowels) {
           auto it = std::remove (el.begin(), el.end(), ch);
           el.erase(it, el.end());
        }       
    }
}