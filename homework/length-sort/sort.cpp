#include "sort.hpp"
#include <algorithm>

bool mySortPredicat(const std::string& l, const std::string& r) {
    auto result = false;

    if (l.length() < r.length()) {
        result = true;
    }
    else if (l.length() == r.length()) {
        result = (l < r);
    }

    return result;
}


std::deque<std::string> lengthSort(std::forward_list<std::string>& strings) {
    std::deque<std::string> deq;
    for (auto& element : strings) {
        deq.push_back(element);
    }

    std::sort(deq.begin(), deq.end(), mySortPredicat);
    return deq;
}
