#include "vowel.hpp"

#include <set>

void removeVowels(std::vector<std::string>& words) {
    std::set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'y', 'A', 'E', 'I', 'O', 'U', 'Y'};
    for (auto& word: words) {
        for (int i = 0; i < word.size(); i++) {
            if (vowels.count(word[i]) == 1) {
                word.erase(i--, 1);
            }
        }
    }
}
