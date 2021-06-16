#include "vowel.hpp"
#include <iostream>

void removeVowels(std::string& text) {
    // for(size_t i = 0; i < text.size(); ++i) {
    //     if(text.at(i) == 'a')
    // }
    auto it = text.begin();
    // for(; it != text.end(); it++) {
    for(; it != text.end();) {
        // std::cout << *it << " ";
        if(*it == 'a' || *it == 'e' || *it == 'i' || *it == 'o' || *it == 'u' || *it == 'y'||
           *it == 'A' || *it == 'E' || *it == 'I' || *it == 'O' || *it == 'U' || *it == 'Y') {
            text.erase(it);
        } 
        else {
            it++;
        }
    }
}

void removeVowels(std::vector<std::string>& words) {
    
    for(std::string& singleString : words) {
        // std::cout << singleString << std::endl;
        // std::cout << "przynajmnie tu jestem" << std::endl;
        removeVowels(singleString);
    }

}