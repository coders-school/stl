#include <algorithm>
#include <forward_list>
#include <string>

#include "sort.hpp"

std::deque<std::string> lengthSort(std::forward_list<std::string>& list){
    list.sort();
    std::deque<std::string> deq{};
    for(auto& listElement : list){
        deq.push_back(listElement);
    }
    std::string tempStr;
    for(auto element : deq){
        for(int i =0; i<(deq.size() -1); i++){
            if(deq[i].size() > deq[i+1].size()){
                tempStr = deq[i];
                deq[i] = deq[i+1];
                deq[i+1] = tempStr;
            }
        }
    }
    return deq;
}
