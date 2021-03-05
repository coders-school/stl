#include "sort.hpp"
#include <algorithm>
#include <iostream>

std::deque<std::string> lengthSort(const std::forward_list<std::string>& list){
    std::deque<std::string> deq;
    for (auto ele : list){
        deq.push_back(ele);
    }

    sort(deq.begin(), deq.end(), [](std::string a, std::string b){ return a < b; });
    return deq;
}