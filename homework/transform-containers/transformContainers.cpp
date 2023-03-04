#include "transformContainers.hpp"

std::map<int, std::string> removeDuplicateAndTranformToMap(std::list<std::string> list,
                                                           std::deque<int> deque) {
    std::map<int, std::string> finalMap;
    std::unique(list.begin(), list.end());
    std::unique(deque.begin(), deque.end());

    std::transform(list.begin(), list.end(), deque.begin(), std::back_inserter(finalMap),
                   [](const auto& listArg, const auto& dequeArg) { return dequeArg, listArg; });
}