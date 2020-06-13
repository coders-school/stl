#include "vowel.hpp"

#include <algorithm>
#include <cctype>

void removeVowels(std::vector<std::string>& words) {
    std::vector<char> vowels{'a', 'e', 'i', 'o', 'u', 'y'};
    std::for_each(words.begin(), words.end(), [&vowels](std::string& word) {
        word.erase(std::remove_if(word.begin(), word.end(), [&vowels](char letter) {
            letter = tolower(static_cast<unsigned char>(letter));
            return std::find(vowels.begin(), vowels.end(), letter) != vowels.end();
        }), word.end());
    });
}