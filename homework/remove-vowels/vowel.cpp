#include "vowel.hpp"
#include <iostream>
#include <vector>
#include <string>

void removeVowels(std::vector<std::string>&vec){
    std::vector <std::string>nvec;
    for (auto &el : vec){
     for(auto it=el.begin(); it<=el.end();){
         if(*it==65 || *it==69 || *it==73 || *it==79 || *it==85 || *it==89 || *it==97||*it==101 || *it==105 || *it==111 || *it ==117 || *it==121){
          it = el.erase(it);
        } else {
            ++it;
              }
     }
    }
}