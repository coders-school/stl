#include "transformContainers.hpp"

#include <algorithm>

std::map<int, std::string> removeDuplicateAndTranformToMap(std::list<std::string> strList, std::deque<int> deq) {
    std::sort(deq.begin(), deq.end());
    strList.sort();

    deq.erase(std::unique(deq.begin(), deq.end()), deq.end());
    strList.erase(std::unique(strList.begin(), strList.end()), strList.end());

    std::map<int, std::string> map;
    std::transform(deq.begin(), deq.end(), strList.begin(), std::inserter(map, map.end()), [](const int& number, const std::string& str) { return std::make_pair(number, str); });

    return map;
}