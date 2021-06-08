#include "sort.hpp"
#include <algorithm>
#include <iostream>

std::deque<std::string> lengthSort(const std::forward_list<std::string>& list) {
    std::deque<std::string> deq;
    for (auto const & ele : list) {
        deq.push_back(ele);
    }
    sort(deq.begin(), deq.end(), [](std::string a, std::string b) { 
        if (a.size() == b.size()) {
            return a < b;
        }
        return a.size() < b.size(); });
    return deq;
}