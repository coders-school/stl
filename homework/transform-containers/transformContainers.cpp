#include "transformContainers.hpp"
#include <algorithm>
#include <iterator>

std::map<int, std::string> removeDuplicateAndTranformToMap(std::list<std::string> list, std::deque<int> deque) {
    list.sort();
    std::sort(deque.begin(), deque.end());
    list.erase(std::unique(list.begin(), list.end()), list.end());
    deque.erase(std::unique(deque.begin(), deque.end()), deque.end());
    std::map<int, std::string> resultMap;
    std::transform(deque.begin(), deque.end(), list.begin(), std::inserter(resultMap, resultMap.end()), [](int first, std::string second) {
        return std::make_pair(first, second);
    });
    return resultMap;
}
