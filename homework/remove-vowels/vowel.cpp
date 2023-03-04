#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include "vowel.hpp"

void removeVowels(std::vector<std::string>& vec)
{
    std::string lancuch;
    for (auto it = vec.begin(); it != vec.end(); ++it)
    {
        lancuch = *it;
        // 'a'
        lancuch.erase(std::remove(lancuch.begin(), lancuch.end(), 'a'), lancuch.end());
         // 'i'
        lancuch.erase(std::remove(lancuch.begin(), lancuch.end(), 'i'), lancuch.end());
         // 'e'
        lancuch.erase(std::remove(lancuch.begin(), lancuch.end(), 'e'), lancuch.end());
         // 'y'
        lancuch.erase(std::remove(lancuch.begin(), lancuch.end(), 'y'), lancuch.end());
         // 'o'
        lancuch.erase(std::remove(lancuch.begin(), lancuch.end(), 'o'), lancuch.end());
          // 'u'
        lancuch.erase(std::remove(lancuch.begin(), lancuch.end(), 'u'), lancuch.end());
          // 'A'
        lancuch.erase(std::remove(lancuch.begin(), lancuch.end(), 'A'), lancuch.end());
         // 'I
        lancuch.erase(std::remove(lancuch.begin(), lancuch.end(), 'I'), lancuch.end());
         // 'E
        lancuch.erase(std::remove(lancuch.begin(), lancuch.end(), 'E'), lancuch.end());
         // 'Y'
        lancuch.erase(std::remove(lancuch.begin(), lancuch.end(), 'Y'), lancuch.end());
         // 'O'
        lancuch.erase(std::remove(lancuch.begin(), lancuch.end(), 'O'), lancuch.end());
          // 'U'
        lancuch.erase(std::remove(lancuch.begin(), lancuch.end(), 'U'), lancuch.end());

        *it = lancuch;
    }
}
