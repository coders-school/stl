#include "transform.hpp"

#include <algorithm>
#include <list>

std::map<int, std::string> removeDuplicateAndTranformToMap(std::list<std::string> list, std::deque<int> deque) {
    list.sort();
    list.erase((std::unique(list.begin(), list.end())), list.end());

    std::sort(deque.begin(), deque.end());
    deque.erase((std::unique(deque.begin(), deque.end())), deque.end());

    std::map<int, std::string> transformedMap{};
    std::transform(deque.begin(), deque.end(), list.begin(), std::inserter(transformedMap, transformedMap.end()),
                   [](const auto& deqElement, const auto& listElement) { return std::make_pair(deqElement, listElement); });

    return transformedMap;
}