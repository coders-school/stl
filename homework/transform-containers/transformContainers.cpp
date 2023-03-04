#include "transformContainers.hpp"

std::map<int, std::string> removeDuplicateAndTranformToMap(std::list<std::string> list,
                                                           std::deque<int> deque) {
    std::map<int, std::string> finalMap;
    list.erase(std::unique(list.begin(), list.end()), list.end());
    deque.erase(std::unique(deque.begin(), deque.end()), deque.end());

    std::transform(list.begin(), list.end(), deque.begin(), std::inserter(finalMap, finalMap.end()),
                   [](const auto& listArg, const auto& dequeArg) { return std::make_pair(dequeArg, listArg); });
    return finalMap;
}