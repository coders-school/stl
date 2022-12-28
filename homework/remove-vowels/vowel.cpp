#include "vowel.hpp"

bool isVowel(char c) {
    std::string vowels = "aeiouyAEIOUY";

    for (std::size_t i = 0; i < vowels.size(); ++i) {
        if (vowels[i] == c) {
            return true;
        }
    }

    return false;
}

void removeVowels(std::vector<std::string>& s) {
    for (auto& el : s) {
        el.erase(std::remove(el.begin(), el.end(), 'a'), el.end());
        el.erase(std::remove(el.begin(), el.end(), 'e'), el.end());
        el.erase(std::remove(el.begin(), el.end(), 'i'), el.end());
        el.erase(std::remove(el.begin(), el.end(), 'o'), el.end());
        el.erase(std::remove(el.begin(), el.end(), 'u'), el.end());
        el.erase(std::remove(el.begin(), el.end(), 'y'), el.end());
        el.erase(std::remove(el.begin(), el.end(), 'A'), el.end());
        el.erase(std::remove(el.begin(), el.end(), 'E'), el.end());
        el.erase(std::remove(el.begin(), el.end(), 'I'), el.end());
        el.erase(std::remove(el.begin(), el.end(), 'O'), el.end());
        el.erase(std::remove(el.begin(), el.end(), 'U'), el.end());
        el.erase(std::remove(el.begin(), el.end(), 'Y'), el.end());
    }
}
