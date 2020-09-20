#include "transformContainers.hpp"

#include <algorithm>

std::map<int, std::string> removeDuplicateAndTranformToMap(std::list<std::string>& list, std::deque<int>& deq) {
    list.sort();
    auto it = std::unique(begin(list), end(list));
    list.erase(it, end(list));

    std::sort(deq.begin(), deq.end());
    list.erase(std::unique(list.begin(), list.end()), list.end());

    std::map<int, std::string> map;

    std::transform(deq.begin(), deq.end(), list.begin(),
                   std::inserter(map, map.end()),
                   [](const int& key, const std::string& value) {
                       return std::make_pair(key, value);
                   });

    return map;
}