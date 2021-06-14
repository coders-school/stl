#include "vowel.hpp"

bool is_vowel(const char& singleCharacter) {
    constexpr char vowels[] = {'a', 'e', 'i', 'o', 'u', 'y', 'A', 'E', 'I', 'O', 'U' , 'Y'};
    return std::find(std::begin(vowels), std::end(vowels), singleCharacter) != std::end(vowels);
}

void removeVowels(std::vector<std::string>& texts) {
    for (std::string& text : texts) {
        auto to_erase = std::remove_if(text.begin(), text.end(), is_vowel);
        text.erase(to_erase, text.end());
    }
}