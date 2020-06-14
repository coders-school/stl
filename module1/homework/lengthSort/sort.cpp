#include "sort.hpp"

#include <algorithm>

std::deque<std::string> lengthSort(std::forward_list<std::string>& list) {
    auto sortByLength = [](auto first, auto second) { return first < second; };

    list.sort(sortByLength);
    list.sort();
    std::deque<std::string> deq{list.begin(), list.end()};

    return deq;
}
