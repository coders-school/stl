#include "sort.hpp"

#include <algorithm>

std::deque<std::string> lengthSort(std::forward_list<std::string> data) {
    data.sort([](const std::string& lhs, const std::string& rhs) {
        return (lhs.size() == rhs.size()) ? (lhs < rhs) : (lhs.size() < rhs.size());
    });

    std::deque<std::string> result;
    std::copy(data.begin(), data.end(), std::back_inserter(result));

    return result;
}
