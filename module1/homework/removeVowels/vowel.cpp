#include "vowel.hpp"

#include <bits/stdc++.h>

#include <algorithm>
#include <array>

void removeVowels(std::vector<std::string>& vec) {
    std::regex vows("[aeiouyAEIOUY]");

    for (auto& str : vec) {
        if (str.empty() == false) {
            str = std::regex_replace(str, vows, "");
        }
    }
}
