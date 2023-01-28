#include "vowel.hpp"

void removeVowels(std::vector<std::string>& words) {
    const std::array<char, 12> arr = {'A', 'E', 'I', 'O', 'U', 'Y',
                                      'a', 'e', 'i', 'o', 'u', 'y'};

    for (auto& word : words) {
        word.erase(std::remove_if(word.begin(), word.end(), [&arr](char c) {
                       return std::find(arr.begin(), arr.end(), c) != arr.end();
                   }),
                   word.end());
    }
}