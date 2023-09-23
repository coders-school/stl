#include "vowel.hpp"
#include <algorithm>
#include <cctype>

void removeVowels(std::vector<std::string>& vec) {
    std::vector<char> vowels = {'a', 'e', 'i', 'o', 'u', 'y', 'A', 'E', 'I', 'O', 'U', 'Y'};
    for (auto& v : vec) {
        for (auto vow : vowels) {
            v.erase(std::remove(v.begin(), v.end(), vow), v.end());
        }
    }
}