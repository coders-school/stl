#include "sort.hpp"

#include <algorithm>
#include <forward_list>
#include <string>

std::deque<std::string> lengthSort(std::forward_list<std::string>& flist) {
    flist.sort([](const std::string& a, const std::string& b) { return a.size() == b.size() ? a < b : a.size() < b.size(); });

    std::deque<std::string> dq;
    for (auto el : flist) {
        dq.push_back(el);
    }

    return dq;
}