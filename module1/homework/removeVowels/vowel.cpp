#include "vowel.hpp"

void removeVowels(std::vector<std::string>& words) {
    std::string vowels ("aeiouyAEIOUY");
    for(auto& sentence : words)
    {
        auto it = std::remove_if(sentence.begin(), sentence.end(),[vowels](auto el){
            if(find(vowels.begin(), vowels.end(), el) != vowels.end()) {
                return true;
            }
            return false;
        });
        sentence.erase(it, sentence.end());
    }
}
