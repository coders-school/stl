#include "sort.hpp"

#include <algorithm>

bool compare(std::string s1, std::string s2) {
    if (s1.size() == s2.size()) {
        return s1 < s2;
    }
    return s1.size() < s2.size();
}

std::deque<std::string> lengthSort(const std::forward_list<std::string>& lst) {
    std::deque<std::string> result;
    for (const auto& el : lst) {
        result.emplace_back(el);
    }

    std::sort(result.begin(), result.end(), compare);
    return result;
}