#include "transformContainerToMap.hpp"

#include <algorithm>

std::map<int, std::string> removeDuplicateAndTranformToMap(std::list<std::string> list, std::deque<int> deq) {
    std::map<int, std::string> transformToMap;

    std::sort(deq.begin(), deq.end());
    deq.erase(std::unique(deq.begin(), deq.end()), deq.end());
    list.sort();
    list.erase(std::unique(list.begin(), list.end()), list.end());

    std::transform(deq.begin(), deq.end(), list.begin(),
                   std::inserter(transformToMap, transformToMap.end()),
                   [](const int& key, const std::string& value) {
                       return std::make_pair(key, value);
                   });

    return transformToMap;
}