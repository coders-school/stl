#include <vector>
#include <string>
#include <algorithm>
#include "vowel.hpp"

void removeVowels(std::vector<std::string> & vec) {
    std::vector<char> Vowels = {'a', 'e', 'i', 'o', 'u', 'y', 'A', 'E', 'I', 'O', 'U', 'Y'};
    for(auto & el : vec) {
        for(char & c : el){
            for(const char & c_V : Vowels) {
                if(c == c_V) {
                    el.erase(remove(el.begin(),el.end(), c), el.end());
                }
            }
        }
    }
}
