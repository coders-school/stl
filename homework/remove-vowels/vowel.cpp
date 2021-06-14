#include "vowel.hpp"
#include <algorithm>
#include <iostream>

void removeVowels(std::vector<std::string>& vec)
{
    const std::string wow = "aeiouyAEIOUY";
    for(auto it = vec.begin(); it != vec.end(); ++it)
    {
        std::string temp = *it;
        std::string new_temp = "";
        for (size_t i = 0; i < temp.length(); i++)
        {
            if (wow.find(temp[i]) == std::string::npos)
            {
               new_temp += temp[i];
            }
            *it = new_temp;
        }
    } 
}