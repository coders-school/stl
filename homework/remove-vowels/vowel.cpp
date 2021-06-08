#include "vowel.hpp"

#include <algorithm>
#include <iostream>

void removeVowels(std::vector<std::string>& vec) {
    std::string str = {"aeiouyAEIOUY"};
    for (auto& ele : vec) {
        for (auto const& s : str) {
            ele.erase(std::remove(ele.begin(), ele.end(), s), ele.end());
        }
    }
}