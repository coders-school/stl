#include "sort.hpp"

#include <algorithm>

bool compare(const std::string& first, const std::string& second) {
    if (first.size() == second.size()) {
        return first < second;
    }
    return first.size() < second.size();
}

std::deque<std::string> lengthSort(std::forward_list<std::string>& flist) {
    std::deque<std::string> dq{flist.begin(), flist.end()};
    std::sort(dq.begin(), dq.end(), compare);
    return dq;
}
