# include "vowel.hpp"

void removeVowels(std::vector<std::string>& collection){
    std::array<char, 12> vw = {'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U', 'y', 'Y'};
    for(int i=0;i<collection.size();i++){
        for(auto it=collection[i].begin();it!=collection[i].end();it++){
            bool isVowel = false;
            for(auto j : vw){
                if(*it == j){
                    isVowel = true;
                }
            }
            if(isVowel){
                collection[i].erase(it);
                it = collection[i].begin();
                if(collection[i].size() == 1){
                    isVowel = false;
                    for(auto j : vw){
                        if(*it == j){
                            isVowel = true;
                        }
                    }
                    if(isVowel){
                        collection[i] = "";
                    }
                }
            }
            if(collection[i].size() == 0){
                break;
            }
        }
    }
}