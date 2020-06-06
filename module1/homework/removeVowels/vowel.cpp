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

void removeVowels(std::vector<std::string>& vec) {
    for (auto& element : vec) {
        for (int i = 0; i < element.size(); ++i) {
            if (isVowel(element[i])) {
                element.erase(std::next(element.begin(), i--));
            }
        }
    }
}
