#include "vowel.hpp"

#include <algorithm>
#include <cctype>

// removes all vowels from a vector of strings
void removeVowels(std::vector<std::string>& texts)
{
    for (auto& text : texts) {
        removeVowels(text);
    }
}

// removes vowels from a single string
void removeVowels(std::string& text)
{
    if (text.empty()) {
        return;
    }

    auto it = std::remove_if(text.begin(), text.end(), isVowel);
    text.erase(it, text.end());
}

// checks if a given char is a vowel
bool isVowel(char letter)
{
    std::string vowels { "aeiouy" };

    return std::any_of(vowels.begin(),
                       vowels.end(),
                       [letter](auto ch) {
                           return ch == tolower(letter);
                       });
}
