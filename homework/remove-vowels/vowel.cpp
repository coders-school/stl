#include "vowel.hpp"
void removeVowels(std::vector<std::string>& vec) {
    std::string vowels = "aeiouyAEIOUY";
    for (auto& el : vec) {
        for (size_t i = 0; i < el.size(); i++) {
            for (size_t j = 0; j < vowels.size(); j++) {
                if (el[i] == vowels[j]) {
                    el.erase(i, 1);
                    i--;
                }
            }
        }
    }
}