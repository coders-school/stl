#include "vowel.hpp"
#include <vector>
std::string clearStringFromVowels(std::string inputString)
{
    int length = inputString.size();
    std::vector<char> vowels {'a','e','i','o','u','y','A','E','I','O','U','Y'};
    std::string outputString = "";
    for(auto it : inputString){
        int ok = 1;
        for(auto it2 : vowels){
            if(it == it2){
                ok = 0;
                continue;
            }       
        }
        if(ok) outputString += it;
    }
    return outputString;
}


void removeVowels(std::vector<std::string>& vecS)
{
    for(int i=0; i < vecS.size(); i++){
        vecS[i] = clearStringFromVowels(vecS[i]);
    }
}