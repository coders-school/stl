#include "transformContainers.hpp"

#include <algorithm>

std::map<int, std::string> removeDuplicateAndTranformToMap(std::list<std::string>& list, std::deque<int>& deque) {
    list.sort();
    list.erase(std::unique(list.begin(), list.end()), list.end());
    std::sort(deque.begin(), deque.end());
    deque.erase(std::unique(deque.begin(), deque.end()), deque.end());

    std::map<int, std::string> removedMap;
    std::transform(deque.cbegin(), deque.cend(), list.cbegin(), std::inserter(removedMap, removedMap.begin()),
                   [](const int& lhs, const std::string& rhs) {
                       return std::pair<int, std::string>{lhs, rhs};
                   });

    return removedMap;
}
