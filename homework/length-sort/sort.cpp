#include <algorithm>
#include <forward_list>
#include <deque>
#include <iostream>
#include <string>

#include "sort.hpp"

std::deque<std::string> lengthSort(std::forward_list<std::string>& list) {
    std::deque<std::string> deq {};
    list.sort();
    for (const auto& ele : list) {
        deq.push_back(ele);
    } 
    std::sort(deq.begin(), deq.end(), [](std::string a, std::string b) {
        return a.length() < b.length();
    });
    return deq;
}
