//
//
#include "vowel.hpp"
#include <iostream>

void removeVowels(std::vector<std::string>& words){
    std::string tempstring{};
    for(auto it=words.begin(); it!=words.end(); ++it){
        for(auto it_s=(*it).begin(); it_s!=(*it).end(); ++it_s){
            if(*it_s != 'e' && *it_s != 'y' && *it_s != 'u' && *it_s != 'i' && *it_s != 'o' && *it_s != 'a' && *it_s != 'E' && *it_s != 'Y' && *it_s != 'U' && *it_s != 'I' && *it_s != 'O' && *it_s != 'A')
            tempstring.push_back(*it_s);
        }
        tempstring.swap(*it);
        tempstring.clear();
        (*it).shrink_to_fit();
    }
    words.shrink_to_fit();
}
