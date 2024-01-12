#include <vector>
#include <array>
#include <iostream>
#include "vowel.hpp"

void removeVowels(std::vector<std::string>& vec) {
    std::array<char, 12> vowels {'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U', 'y', 'Y'};
    for (std::string& each_string : vec) {
        for (auto it = each_string.begin(); it != each_string.end(); ++it) {
            for (const auto& vowel : vowels) {
                if (*it == vowel) {
                    each_string.erase(it);
                    --it;
                    break;
                }
            }
        }
    }
}
