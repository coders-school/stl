#include "vowel.hpp"

#include <algorithm>
#include <iostream>

void removeVowels(std::vector<std::string>& vec){
    std::string del = { "aeiouyAEIOUY" };
    for (auto& ele : vec) {
        for (auto const & vowel : del){
            ele.erase(std::remove(ele.begin(), ele.end(), vowel), ele.end());
        }
    }
}