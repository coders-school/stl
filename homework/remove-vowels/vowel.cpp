#include "vowel.hpp"

#include<algorithm>

void removeVowels(std::vector<std::string>& vec) {

    std::string str {"aeiouyAEIOUY"};

    for(auto& el : vec) {
        for(auto& el_ch : str) {
            el.erase(std::remove(el.begin(), el.end(), el_ch), el.end());
        }
    }
}

void removeVowels_ver2(std::vector<std::string>& vec) {
    std::vector<std::string> vow = {"a","e","i","o","u","y","A","E","I","O","U","Y"};

    for(auto& el_v : vow) {
        auto i{0};
        while(i < vec.size()) {
            auto pos = vec[i].find(el_v);
            if(pos == -1) {
                ++i;
                continue;
            }
            auto its = vec[i].begin();
            std::advance(its,pos);
            vec[i].erase(its);
        }
    }
}
