#include "sort.hpp"

#include <algorithm>

std::deque<std::string> lengthSort(const std::forward_list<std::string>& listToSort) {
    std::deque<std::string> deq;

    std::copy(listToSort.begin(), listToSort.end(), std::back_inserter(deq));

    std::sort(deq.begin(), deq.end(), [](const auto& leftString, const auto& rightString) {
        if (leftString.size() == rightString.size()) {
            return leftString < rightString;
        }
        return leftString.size() < rightString.size();
    });
    return deq;
}