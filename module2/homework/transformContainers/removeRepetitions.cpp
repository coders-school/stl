#include "removeRepetitions.hpp"

#include <algorithm>
#include <iterator>

std::map<int, std::string> removeDuplicateAndTranformToMap(std::list<std::string>& lst,
                                                           std::deque<int>& deq) {
    lst.sort();
    auto listIt = std::unique(lst.begin(), lst.end());
    lst.erase(listIt, lst.end());

    std::sort(deq.begin(), deq.end());
    auto deqIt = std::unique(deq.begin(), deq.end());
    deq.erase(deqIt, deq.end());

    std::map<int, std::string> resultMap;
    std::transform(deq.begin(),
                   deq.end(),
                   lst.begin(),
                   std::inserter(resultMap, resultMap.end()),
                   [](const auto& elDeq, const auto& elLst) {
                       return std::make_pair(elDeq, elLst);
                   });
                   
    return resultMap;
}
