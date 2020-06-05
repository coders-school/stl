#include "vowel.hpp"

#include <cctype>
#include <vector>

bool isVowel(char ch) {
    switch (tolower(ch)) {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
    case 'y':
        return true;
        break;
    default:
        return false;
        break;
    }
}
//segmentation fault here 
void removeVowels(std::vector<std::string>& vec) {
    for (auto& element : vec) {
        for (auto it = element.begin(); it != element.end(); ++it) {
            if (isVowel(*it)) {
                element.erase(it);
            }
        }
    }
}