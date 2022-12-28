#include "sort.hpp"

bool compareString(const std::string& s1, const std::string& s2) {
    if (s1.size() < s2.size()) {
        return true;
    } else if (s1.size() == s2.size()) {
        return s1 < s2;
    }

    return false;
}

std::deque<std::string> lengthSort(std::forward_list<std::string>& fl) {
    fl.sort(compareString);
    std::deque<std::string> dq = {};

    for (auto& el : fl) {
        dq.push_back(el);
    }

    return dq;
}
