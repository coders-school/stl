#include "vowel.hpp"
#include <algorithm>
#include <cctype>
#include <iostream>
using namespace std;
//"aoeiyuAOEIYU"

void removeVowels(std::vector<std::string>& vs){
    for(auto& elv : vs){

      /*for(auto i = elv.begin(); i < elv.end();){
            if((*i) == 'a' || (*i) == 'A' || (*i) == 'o'|| (*i) == 'O' ||
               (*i) == 'e' || (*i) == 'E' || (*i) == 'i' || (*i) == 'I') {
                elv.erase(i);
            }
            else i++;    
        }*/

        for(auto i = elv.begin(); i < elv.end();){
           char c = tolower(*i);
           if(c == 'a' || c == 'o' || c == 'e'|| c == 'i' || c== 'y' || c == 'u') {
             elv.erase(i);
           }
           else i++;   
        }
    }

}