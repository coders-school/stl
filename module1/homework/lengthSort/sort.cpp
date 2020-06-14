#include "sort.hpp"

#include <algorithm>

bool compare(const std::string& s1, const std::string& s2) {
    return s1.size() < s2.size();
}

std::deque<std::string> lengthSort(std::forward_list<std::string>& str) {
    str.sort();
    std::deque<std::string> sortMe;

    for (const auto& el : str) {
        sortMe.push_back(el);
    }
    std::sort(sortMe.begin(), sortMe.end(), compare);

    return sortMe;
}
