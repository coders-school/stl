#include "vowel.hpp"

void removeVowels(std::vector<std::string> &vec) {
    const std::vector<char> vowels{'a', 'e', 'i', 'o', 'u', 'y'};
    std::for_each(begin(vec), end(vec), [&](auto &s) {
        s.erase(remove_if (begin(s), end(s), [&](auto c) {
            return find(cbegin(vowels), cend(vowels), tolower(c)) != cend(vowels); 
        }), end(s)); 
    });
}
