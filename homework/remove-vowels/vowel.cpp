#include <iostream>
#include <string>
#include "vowel.hpp"
#include <vector>
#include <algorithm>

std::vector<std::string> removeVowels(std::vector<std::string> strvec)
{
    std::vector<char> vowels = {'a', 'e', 'i', 'o', 'u', 'y', 'A','E','I','O','U','Y'};

    for(auto& j : strvec)
    {
        for (int i = 0; i < j.length(); i++)
        {
            if (std::find(vowels.begin(), vowels.end(), j[i]) != vowels.end())
            {
                j = j.replace(i, 1, "");
                i -= 1;
            }
        }
    }
    return strvec;
}