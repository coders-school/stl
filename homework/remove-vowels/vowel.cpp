#include "vowel.hpp"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void removeVowels(std::vector<std::string>& vec) {
    std::string vowels = "aAeEiIoOuUyY";

    for (auto& el : vec) {
        for (const auto& v : vowels) {
            auto fun = [v](auto n) {if(v ==n) return true; return false; };
            auto removing = std::remove_if(el.begin(), el.end(), fun);
            el.erase(removing, el.end());
        }
    }
}