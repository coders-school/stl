#include "transform.hpp"

std::map<int, std::string> removeDuplicateAndTranformToMap(std::list<std::string> list, std::deque<int> deque) {
    std::sort(deque.begin(), deque.end());
    std::unique(deque.begin(), deque.end());

    list.sort();
    auto lastElem = std::unique(list.begin(), list.end());
    list.erase(lastElem, list.end());

    std::map<int, std::string> map;

    auto zip = [](const int i, std::string& s) { return std::make_pair(i, s); };
    std::transform(deque.begin(), deque.end(), list.begin(), std::inserter(map, map.end()), zip);

    return map;
}