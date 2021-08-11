#include <vector>
#include <string>
#include <algorithm>
#include "vowel.hpp"


void removeVowels(std::vector<std::string> & vec) {
    std::vector<char> vowels {'a', 'e', 'i', 'o', 'u', 'y', 'A', 'E', 'I', 'O', 'U', 'Y'};
    for(auto & el : vec) {
        for(const auto & c_V : vowels) {
            el.erase(remove(el.begin(),el.end(), c_V), el.end());
        }
    }
}
