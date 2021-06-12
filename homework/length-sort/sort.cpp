#include "sort.hpp"

#include <algorithm>

std::deque<std::string> lengthSort(const std::forward_list<std::string>& stringsList) {
    std::deque<std::string> sorted;

    for (const auto& i : stringsList) {
        auto it = std::lower_bound(begin(sorted), end(sorted), i, [](const std::string& firstString, const std::string& secondString) {
            return (firstString.size() == secondString.size()) ? (firstString < secondString) : (firstString.size() < secondString.size());
        });

        sorted.insert(it, i);
    }
    return sorted;
}
