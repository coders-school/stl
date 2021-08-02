#include "vowel.hpp"
#include <algorithm>

void removeVowels(std::vector<std::string> &vec)
{
    for (auto & j : vec)
    {
        for (const auto &i : vowels)
        {
            j.erase(std::remove(j.begin(), j.end(), i), j.end());
        }
    }
}
