#include "sort.hpp"

#include <algorithm>

std::deque<std::string> lengthSort(const std::forward_list<std::string>& list){
    std::deque<std::string> queue;
    for(const auto& el : list){
        queue.push_back(el);
    }
    std::sort(queue.begin(), queue.end(), [](std::string it, std::string it2){
        if(it.size() == it2.size()){
            return it < it2;
        }
        return it.size() < it2.size();
    });
    
    return queue;
}
