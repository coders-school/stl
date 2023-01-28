#include "vowel.hpp"

void removeVowels(std::vector<std::string> &words)
    {
    for (auto &word : words) 
    {
        word.erase(std::remove_if(word.begin(), word.end(), [](char c) {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
        }), word.end());
    }
}