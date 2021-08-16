#include "transform.hpp"

std::map<int, std::string> removeDuplicateAndTranformToMap(std::list<std::string>& list, std::deque<int>& deque) {
    list.sort();
    list.unique();
    std::sort(deque.begin(), deque.end());
    auto last = std::unique(deque.begin(), deque.end());
    deque.erase(last, deque.end());

    std::map<int, std::string> map;

    std::transform(deque.begin(),
                   deque.end(),
                   list.begin(),
                   std::inserter(map, map.begin()),
                   [](const auto& first, const auto& second) {
                       return std::make_pair(first, second);
                   });

    return map;
}