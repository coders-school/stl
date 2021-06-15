#include "sort.hpp"
#include <algorithm>
#include <deque>
#include <forward_list>
#include <string>

bool isEqualSize(const std::string& lhs, const std::string& rhs) {
    if (lhs.size() == rhs.size()) {
        return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
    }
    return lhs.size() < rhs.size();
}

std::deque<std::string> lengthSort(const std::forward_list<std::string>& list) {
    std::deque<std::string> returnResult{};
    returnResult.insert(returnResult.begin(), list.begin(), list.end());
    std::stable_sort(returnResult.begin(), returnResult.end(), isEqualSize);

    return returnResult;
}