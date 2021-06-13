#include "sort.hpp"
#include <algorithm>
#include <deque>
#include <iostream>

std::deque<std::string> lengthSort(std::forward_list<std::string>& words){
    std::deque<std::string> deq{};
    auto it = words.begin();
    for(const auto& el : words){
        deq.push_back(*it);
        std::advance(it,1);
    }

    bool swapped;
    do{
        swapped = false;
        for(int i=0; i<(deq.size()-1); ++i){
            if( (deq.at(i)).size() > (deq.at(i+1)).size() ){
                std::swap(deq.at(i), deq.at(i+1));
                swapped = true;
            }
            else if( (deq.at(i)).size() == (deq.at(i+1)).size() &&
                    deq.at(i) > deq.at(i+1)){
                std::swap(deq.at(i), deq.at(i+1));
                swapped = true;
            }
        }
    }while(swapped);

    return deq;
}
