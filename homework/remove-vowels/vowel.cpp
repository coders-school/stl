#include "vowel.hpp"

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
