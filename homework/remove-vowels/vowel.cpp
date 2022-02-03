#include "vowel.hpp"
#include <iterator>
#include <numeric>
#include <algorithm>

bool isVowel(char letter){
    //std::string vowels = "aeiouyAEIOUY";
    if(std::find(vowels.cbegin(),vowels.cend(),letter) != std::end(vowels)){
        return true;
    }
    return false;
    
    /*if (letter == 'a' || letter == 'e' || letter == 'i'
        || letter == 'o' || letter == 'u' || letter == 'y'
        || letter == 'A' || letter == 'E' || letter == 'I'
        || letter == 'O' || letter == 'U' || letter == 'Y'){
            return false;
        }
    return true;*/
}

void removeVowels(std::vector<std::string>& vecToAnalize){
    /* auto withoutVowels = [](std::string result, const char c){
        return isVowel(c) ? result += c : result;
    }; */
    for(auto& e: vecToAnalize){       
        e.erase(std::remove_if(e.begin(),
                                e.end(),
                                [](const char letter){return isVowel(letter);}),
                e.end());
        
       /* std::string eNew = std::accumulate(e.begin(),e.end(),std::string(),withoutVowels);
       e = eNew; */
    }
}