#include "sort.hpp"

#include <algorithm>

bool compare(const std::string& lhs, const std::string& rhs) {
    if(lhs.size() == rhs.size()) {
        return lhs < rhs;
    }
    return lhs.size() < rhs.size();
}

std::deque<std::string> lengthSort(const std::forward_list<std::string>& input) {
    if(input.empty()) {
        std::deque<std::string> returnVal{};
        return returnVal;
    }
    size_t containerSize = std::distance(input.begin(), input.end());
    std::deque<std::string> returnVal(containerSize);
    std::copy(input.begin(), input.end(), returnVal.begin());
    std::sort(returnVal.begin(), returnVal.end(), compare);
    return returnVal;
}