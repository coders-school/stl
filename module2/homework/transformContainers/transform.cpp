#include "transform.hpp"
#include <algorithm>

std::map<int, std::string> removeDuplicateAndTranformToMap(std::list<std::string> lst, std::deque<int> deq)
{
    std::map<int, std::string> map;

    lst.sort();
    std::sort(deq.begin(), deq.end());
    auto last = std::unique(deq.begin(), deq.end());
    deq.erase(last, deq.end());
    lst.unique();
    std::transform(deq.begin(), deq.end(), lst.begin(), std::inserter(map, map.end()), [&map](int &deqElement, std::string &lstElement)
        { return std::make_pair(deqElement, lstElement); 
    });
    return map;
}