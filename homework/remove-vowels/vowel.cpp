#include "vowel.hpp"

void removeVowels(std::vector<std::string> &words)
{
    const std::string vowels = {"aeiouyAEIOUY"};
    for (auto &el : words)
    {
        for (const auto &c : vowels)
        {
            el.erase(std::remove(el.begin(), el.end(), c), el.end());
        }
    }
}