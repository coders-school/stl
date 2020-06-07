#include "sort.hpp"

std::deque<std::string> lengthSort(std::forward_list<std::string> lst) {
    std::deque<std::string> dq;
    for (auto it = lst.begin(); it != lst.end(); it++) {
        dq.emplace_back(*it);
    }

    std::sort(dq.begin(), dq.end(), [](const auto& lhs, const auto& rhs) {
        if (lhs.size() < rhs.size()) {
            return true;
        } else if (lhs.size() == rhs.size()) {
            if (lhs < rhs) {
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    });
    return dq;
}