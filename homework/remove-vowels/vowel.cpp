#include "vowel.hpp"

void removeVowels(std::vector<std::string>& collection) {
    std::vector<char> vowels{'a', 'e', 'i', 'o', 'u', 'y'};

    for(int i = 0; i < collection.size(); ++i) {
        std::string temp;
        for(char character: collection[i]) {
            bool wasVowel = false;
            for(char vowel: vowels) {
                if(tolower(character) == vowel) {
                    wasVowel = true;
                    break;
                }
            }
            if(!wasVowel) {
                temp += character;
            }
        }
        collection[i] = temp;
    }
}