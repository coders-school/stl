#include <iostream>
#include "vowel.hpp"



void removeVowels(std::vector<std::string>& vec){

    std::string str = {"aeiouyAEIOUY"};
    for (auto& ele : vec){
        for (int i = 0; i < ele.size(); i++){
            for (auto & str_ele : str){
                if (ele[i] == str_ele){
                    ele.erase(ele.begin() + i);
                    i--;
                    break;
                }
            }
        }
    }
}