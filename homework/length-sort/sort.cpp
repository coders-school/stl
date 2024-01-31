#include "sort.hpp"
#include <algorithm>
#include <iostream>

bool sortLex(const std::string& first, const std::string& second) {
    if (first.length() != second.length()) {
        return first.length() < second.length();
    }

    return first < second;
}

std::deque<std::string> lengthSort(std::forward_list<std::string>& fl) {
    fl.sort([](const std::string& first, const std::string& second) { return sortLex(first, second); });

    std::deque<std::string> deq(fl.begin(), fl.end());

    return deq;
}
