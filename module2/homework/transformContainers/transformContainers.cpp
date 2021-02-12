#include "transformContainers.hpp"

std::map<int, std::string> removeDuplicateAndTranformToMap(std::list<std::string> list, std::deque<int> deque) {
    list.sort();
    list.erase((std::unique(begin(list), end(list))), end(list));

    std::sort(deque.begin(), deque.end());
    deque.erase((std::unique(begin(deque), end(deque))), end(deque));

    std::map<int, std::string> outputMap{};

    if (list.size() == deque.size()) {
        std::transform(deque.begin(), deque.end(), list.begin(),
                       std::inserter(outputMap, outputMap.end()),
                       [](const int dequeValue, const std::string& listValue) {
                           return std::make_pair(dequeValue, listValue);
                       });
    }
    return outputMap;
}