
#include <algorithm>
#include <iostream>
#include "vowel.hpp"

void removeVowelsfromStr(std::string& str)
{
    for(char i : "aAeEyYuUiIiOo")
    {
        str.erase(std::remove(std::begin(str), std::end(str), i), std::end(str));
    }
}

void removeVowels(std::vector<std::string>& vec)
{
    for(auto & s : vec) 
    {
        removeVowelsfromStr(s);
    }
}
 
