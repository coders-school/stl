#include "vowel.hpp"


bool isVowel(const char letter){
    constexpr int vowelsArraySize = 12;
    constexpr std::array<char, vowelsArraySize> vowels = {'A', 'E', 'I', 'O', 'U', 'Y',
                                                          'a', 'e', 'i', 'o', 'u', 'y'};

    return std::find(vowels.begin(),vowels.end(),letter) != vowels.end();
}

void removeVowels(std::vector<std::string>& strings) {

    for (auto& elem : strings) {
         auto vowelsToRemove = std::remove_if(elem.begin(),elem.end(),isVowel);
         elem.erase(vowelsToRemove,elem.end());
    }
}