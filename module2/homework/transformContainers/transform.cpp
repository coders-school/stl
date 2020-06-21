#include "transform.hpp"

#include <algorithm>

std::map<int, std::string> removeDuplicateAndTransformToMap (std::list<std::string>& list, std::deque<int>& deque) {
    std::map<int, std::string> resultMap;

    list.sort();
    list.erase(std::unique(begin(list), end(list)), end(list));

    std::sort(begin(deque), end(deque));
    deque.erase(std::unique(begin(deque), end(deque)), end(deque));

    std::transform(list.begin(), list.end(), deque.begin(), std::inserter(resultMap, resultMap.end()),
            [](const std::string& elOfList, const int& elOfDeque) { return std::make_pair(elOfDeque, elOfList); });

    return resultMap;
}

