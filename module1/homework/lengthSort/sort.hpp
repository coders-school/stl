#pragma once

#include <deque>
#include <forward_list>
#include <string>

auto compare = [](const std::string& s1, const std::string& s2) {
    if (s1.size() != s2.size()) {
        return s1.size() < s2.size();
    } else {
        return s1 < s2;
    }
};

std::deque<std::string> lengthSort(const std::forward_list<std::string>&);
