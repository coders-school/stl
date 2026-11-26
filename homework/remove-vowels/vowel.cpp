#include "vowel.hpp"
#include <string>
#include <vector>

void removeVowels(std::vector<std::string>& words) {
    for (auto& word : words) {
        std::string result;
        for (const auto& ch : word) {
            if (ch != 'A' && ch != 'E' && ch != 'I' && ch != 'O' && ch != 'U' && ch != 'Y' &&
                ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u' && ch != 'y') {
                result += ch;
            }
        }
        word = result;
    }
}
