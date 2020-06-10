#include "sort.hpp"

#include <algorithm>
#include <deque>
#include <forward_list>
#include <string>

std::deque<std::string> lengthSort(std::forward_list<std::string>& f) {
    std::deque<std::string> d;

    for (const auto &i : f) {
        auto it = std::lower_bound(begin(d), end(d), i, pred);
        d.insert(it, i);
    }
    return  d;
}

bool pred(const std::string& a, const std::string& b) {
    if (a.size() == b.size())
        return a < b;

    return a.size() < b.size();
}
