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

    for (const auto& el : listToSort) {
        result.push_back(el);
    }

    return result;
}
