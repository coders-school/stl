#include <algorithm>
#include <iterator>
#include "transform.hpp"

std::map<int, std::string> removeDuplicateAndTranformToMap(std::list<std::string>& list, std::deque<int>& deq) {
    list.sort();
    list.erase(std::unique(list.begin(), list.end()), list.end());

    std::sort(deq.begin(), deq.end());
    deq.erase(std::unique(deq.begin(), deq.end()), deq.end());

    if (list.size() != deq.size()) {
        return {};
    }
    std::map<int, std::string> map;
    std::transform(deq.begin(), deq.end(), list.begin(), std::inserter(map, map.end()),
                   [](auto value, const auto& str) {
                       return make_pair(value, str);
                   });
    return map;
} 