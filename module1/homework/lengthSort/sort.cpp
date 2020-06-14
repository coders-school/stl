#include "sort.hpp"

std::deque<std::string> lengthSort(std::forward_list<std::string> listToSort) {
    listToSort.sort([](const std::string& lhs, const std::string& rhs) {
        if (lhs.size() == rhs.size()) {
            return lhs <= rhs;
        }

        return lhs.size() <= rhs.size();
    });

    return std::deque<std::string>(listToSort.cbegin(), listToSort.cend());
}
