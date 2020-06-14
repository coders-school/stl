#include "vowel.hpp"

#include <algorithm>

const std::vector<char> letters{'a', 'e', 'i', 'o', 'u', 'y'};

void removeVowels(std::vector<std::string>& words){
    for(auto &word : words){
        for(auto &letter : letters){
            const int loop = std::count(word.begin(), word.end(), letter);
            for(int i = 0; i < loop; i++){
                word.erase(word.find(letter), 1);
            }
        }
    }
}