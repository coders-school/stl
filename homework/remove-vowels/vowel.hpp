#include <vector>
#include <iostream>
#include <algorithm>

void removeVowels(std::vector<std::string>& words){

    std::vector<char> vowels {'a', 'e', 'i', 'o', 'u'};
    for(int i = 0; i < words.size(); i++){
        for(char vowel : vowels){
            words[i].erase(std::remove(words[i].begin(), words[i].end(), vowel), words[i].end());
        }
    }
};