#include "vowel.hpp"

void removeVowels(std::vector<std::string>& input){

    std::string vowels{"AEIOUYaeiouy"};
    std::string temp;

    for (auto & el : input){
        for (size_t i = 0; i < el.size(); ++i){
            for (auto & el2 : vowels){
                if (el.at(i) == el2){
                    el.at(i) = '~';
                    break;
                }
            }
        }
        for (size_t i = 0; i< el.size(); ++i){
            if(el.at(i) !='~'){
                temp += el.at(i);
            }
        }

        el = temp;
        temp.clear();
    }


}