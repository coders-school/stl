#include "sort.hpp"

std::deque<std::string> lengthSort(std::forward_list<std::string> listToSort) {
    auto sortPred = [](const std::string& lhs, const std::string& rhs) {
        if (lhs.size() == rhs.size()) {
            return lhs <= rhs;
        }

        return lhs.size() <= rhs.size();
    };

    listToSort.sort(sortPred);

    std::deque<std::string> result;

    result.insert(result.cbegin(), listToSort.cbegin(), listToSort.cend());

    return result;
}
