#include "vowel.hpp"

std::vector<std::string> removeVowels(std::vector<std::string>& words){
    std::vector<char> vowels = {'A', 'a', 'E', 'e', 'I', 'i', 'O', 'o', 'U', 'u', 'Y', 'y'};
    for(auto& word:words){
        std::vector<size_t> temp;
        for(size_t i = 0; i < word.size(); ++i){
            for(size_t j = 0; j < vowels.size(); ++j){
                if(word[i] == vowels[j]){
                    auto it = temp.begin();
                    temp.insert(it, i);
                    break;
                }
            }
        }
        for(auto el:temp){
            word.erase(el, 1);
        }
        temp.clear();
    }
    return words;
}