#include "vowel.hpp"
#include <iostream>
#include <string> 
#include <vector> 


std::vector <std::string> removeVowels (std::vector<std::string> &word){

    std::vector<std::string> newVector;
    
    for (int i = 0; i < word.size(); i++){
       std::string newString;
        std::string newWord = word.at(i);
        for (auto ele : newWord){
        if (ele != 'a' && ele != 'e' && ele != 'i' && ele != 'o' && ele != 'u' && ele != 'y' && ele != 'A' && ele != 'E' && ele != 'I' && ele != 'O' && ele != 'U' && ele != 'Y'){
        newString += ele;
        }
    }
    newVector.push_back(newString);
   }
    return word = newVector;
}
