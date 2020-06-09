#include "transform.hpp"

#include <algorithm>
#include <iterator>

std::map<int, std::string> removeDuplicateAndTranformToMap(std::list<std::string> list, std::deque<int> deque) {
    list.sort();
    list.unique();
    std::sort(deque.begin(), deque.end());
    deque.erase(std::unique(deque.begin(), deque.end()), deque.end());

    std::map<int, std::string> result;
    std::transform(list.cbegin(), list.cend(), deque.cbegin(), std::inserter(result, result.end()), [](const auto& str, auto num) { return std::make_pair(num, str); });

    return result;
}
