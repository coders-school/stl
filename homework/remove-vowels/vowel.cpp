#include "vowel.hpp"
#include <cctype>
#include <iostream>
using namespace std;

void removeVowels(std::vector<std::string>& vs) {
    for (auto& elv : vs) {
        for (auto i = elv.begin(); i < elv.end();) {
            char c = tolower(*i);
            if (c == 'a' || c == 'o' || c == 'e' || c == 'i' || c == 'y' || c == 'u') {
                elv.erase(i);
            } else
                i++;
        }
    }
}