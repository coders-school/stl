#include "vowel.hpp"
#include <algorithm>
#include <string>
#include <vector>

#include <iostream>

void removeVowels(std::vector<std::string>& vec) {
    std::string vowels{"AEIOUYaeiouy"};
    for (auto& x : vec) {
        x.erase(std::remove_if(x.begin(), x.end(), [=](char c) {
                    if (auto itr = vowels.find(c); itr != std::string::npos) {
                        return true;
                    } else {
                        return false;
                    }
                }),
                x.end());
        if (x.size() == 0) {
            x.clear();
        }
    }
}