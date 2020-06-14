#include "sort.hpp"

#include <algorithm>

bool comparator(const std::string& firstString, const std::string& secondString) {
    return firstString.length() < secondString.length();
}

std::deque<std::string> lengthSort(std::forward_list<std::string> list) {
    list.sort();
    std::deque<std::string> deq{list.begin(), list.end()};
    std::sort(deq.begin(), deq.end(), comparator);

    return deq;
}
