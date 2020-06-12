#include <algorithm>
#include "vowel.hpp"

void removeVowelsfromWord(std::string& word)
{
    for (char i : "aAeEyYuUiIiOo")
    {
        word.erase(std::remove(std::begin(word), std::end(word), i), std::end(word));
    }
}

void removeVowels(std::vector<std::string>& words)
{
    for (auto& s : words)
    {
        removeVowelsfromWord(s);
    }
}
