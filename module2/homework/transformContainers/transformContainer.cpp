#include "transformContainer.hpp"

#include <algorithm>

std::map<int, std::string> removeDuplicateAndTranformToMap(const std::list<std::string>& list,
                                                           const std::deque<int>& deq) {
    std::list<std::string> uniqueList{list.begin(), list.end()};
    uniqueList.sort();
    uniqueList.erase(std::unique(uniqueList.begin(), uniqueList.end()), uniqueList.end());

    std::deque<int> uniqueDeq{deq.begin(), deq.end()};
    std::sort(uniqueDeq.begin(), uniqueDeq.end());
    uniqueDeq.erase(std::unique(uniqueDeq.begin(), uniqueDeq.end()), uniqueDeq.end());

    std::map<int, std::string> map;
    auto deqIt = uniqueDeq.begin();
    std::transform(uniqueList.begin(), uniqueList.end(), std::inserter(map, map.end()), [&deqIt](const auto &el) {
        auto pair = std::make_pair(*deqIt, el);
        deqIt++;
        return pair;
    });

    return map;
}
