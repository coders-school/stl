#include "sort.hpp"

#include <algorithm>

std::deque<std::string> lengthSort(const std::forward_list<std::string>& unsortedList) {
    std::deque<std::string> sortedDeque(unsortedList.begin(), unsortedList.end());

    std::sort(sortedDeque.begin(), sortedDeque.end(), [](const auto& lhs, const auto& rhs) {
        if (lhs.size() == rhs.size()) {
            return lhs < rhs;
        } else {
            return lhs.size() < rhs.size();
        }
    });
    return sortedDeque;
}
