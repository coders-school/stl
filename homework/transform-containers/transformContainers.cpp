#include "transformContainers.hpp"

std::map<int, std::string> removeDuplicateAndTranformToMap(std::list<std::string> list,
                                                           std::deque<int> deque) {
    std::map<int, std::string> finalMap;

    std::set<std::string> newList;
    std::set<int> newInt;
    std::copy(list.begin(), list.end(), std::inserter(newList, newList.end()));
    std::copy(deque.begin(), deque.end(), std::inserter(newInt, newInt.end()));

    // list.erase(std::unique(list.begin(), list.end()), list.end());
    // deque.erase(std::unique(deque.begin(), deque.end()), deque.end());

    std::transform(newList.begin(), newList.end(), newInt.begin(), std::inserter(finalMap, finalMap.end()),
                   [](const auto& listArg, const auto& dequeArg) { return std::make_pair(dequeArg, listArg); });
    for (const auto& a : finalMap) {
        std::cout << a.first << " " << a.second << std::endl;
    }
    return finalMap;
}