#include <algorithm>
#include <iostream>
#include "vowel.hpp"


void printWords(const std::vector<std::string>& v) {
    std::cout << "---------------------------------" << std::endl;

    for (auto elem : v) {
        std::cout << elem << std::endl;
    }

    std::cout << "---------------------------------" << std::endl;
}

bool isVowel(char c) {
    return (c == 'a' || c == 'o' || c == 'e' || c == 'i' || c == 'u' || c == 'y' || c == 'A' || c == 'O' || c == 'E' || c == 'I' || c == 'U' || c == 'Y');
}

void removeVowels(std::vector<std::string>& v) {
    for (auto& word : v) {
        word.erase(std::remove_if(word.begin(), word.end(), isVowel), word.end());
    }
}