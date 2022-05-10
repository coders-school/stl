#include "vowel.hpp"
#include <algorithm>

void removeVowels(std::vector<std::string>& vec) {
    for (auto& el : vec) {
        el.erase(std::remove_if(el.begin(), el.end(),
                                [](unsigned char ch) {
                                    return (ch == 'a' || ch == 'A' ||
                                            ch == 'e' || ch == 'E' ||
                                            ch == 'i' || ch == 'I' ||
                                            ch == 'o' || ch == 'O' ||
                                            ch == 'u' || ch == 'U' ||
                                            ch == 'y' || ch == 'Y');
                                }),
                 el.end());
    }
}