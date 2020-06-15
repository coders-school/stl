#include "sort.hpp"

#include <algorithm>
#include <deque>
#include <forward_list>
#include <string>

std::deque<std::string> lengthSort(std::forward_list<std::string>& list) {
    std::deque<std::string> sorted;

    for (const auto &i : list) {
        auto it = std::lower_bound(begin(sorted), end(sorted), i, pred);
        sorted.insert(it, i);
    }
    return sorted;
}

bool pred(const std::string& a, const std::string& b) {
    if (a.size() == b.size())
        return a < b;

    return a.size() < b.size();
}
