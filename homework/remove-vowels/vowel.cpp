#include "vowel.hpp"

void removeVowels(std::string& text) {
    for(auto it = text.begin(); it != text.end();) {
        if(*it == 'a' || *it == 'e' || *it == 'i' || *it == 'o' || *it == 'u' || *it == 'y'||
           *it == 'A' || *it == 'E' || *it == 'I' || *it == 'O' || *it == 'U' || *it == 'Y') {
            text.erase(it);
        } else {
            ++it;
        }
    }
}

void removeVowels(std::vector<std::string>& words) {
    for(std::string& singleString : words) {
        removeVowels(singleString);
    }
}