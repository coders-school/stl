#include <algorithm>

#include "vowel.hpp"

void removeVowels(std::vector<std::string>& vec){
    std::string vow = "aeiouyAEIOUY";

    for(size_t i = 0; i < vec.size(); i++){
        auto& str = vec[i];
        for(const auto& letter : vow) {
            str.erase(std::remove(str.begin(), str.end(), letter), str.end());
        }
    }
}
