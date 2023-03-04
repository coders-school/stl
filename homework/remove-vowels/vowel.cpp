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
        auto newEndIt_a = std::remove(lancuch.begin(), lancuch.end(), 'a');
        lancuch.erase(newEndIt_a, lancuch.end());
         // 'i'
        auto newEndIt_i = std::remove(lancuch.begin(), lancuch.end(), 'i');
        lancuch.erase(newEndIt_i, lancuch.end());
         // 'e'
        auto newEndIt_e = std::remove(lancuch.begin(), lancuch.end(), 'e');
        lancuch.erase(newEndIt_e, lancuch.end());
         // 'y'
        auto newEndIt_y = std::remove(lancuch.begin(), lancuch.end(), 'y');
        lancuch.erase(newEndIt_y, lancuch.end());
         // 'o'
        auto newEndIt_o = std::remove(lancuch.begin(), lancuch.end(), 'o');
        lancuch.erase(newEndIt_o, lancuch.end());
          // 'u'
        auto newEndIt_u = std::remove(lancuch.begin(), lancuch.end(), 'u');
        lancuch.erase(newEndIt_u, lancuch.end());
          // 'A'
        auto newEndIt_A = std::remove(lancuch.begin(), lancuch.end(), 'A');
        lancuch.erase(newEndIt_A, lancuch.end());
         // 'I
        auto newEndIt_I = std::remove(lancuch.begin(), lancuch.end(), 'I');
        lancuch.erase(newEndIt_I, lancuch.end());
         // 'E
        auto newEndIt_E = std::remove(lancuch.begin(), lancuch.end(), 'E');
        lancuch.erase(newEndIt_E, lancuch.end());
         // 'Y'
        auto newEndIt_Y = std::remove(lancuch.begin(), lancuch.end(), 'Y');
        lancuch.erase(newEndIt_Y, lancuch.end());
         // 'O'
        auto newEndIt_O = std::remove(lancuch.begin(), lancuch.end(), 'O');
        lancuch.erase(newEndIt_O, lancuch.end());
          // 'u'
        auto newEndIt_U = std::remove(lancuch.begin(), lancuch.end(), 'U');
        lancuch.erase(newEndIt_U, lancuch.end());

        std::cout << lancuch << '\n';
        *it = lancuch;
      
    }

}
