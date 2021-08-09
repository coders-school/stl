#include "transcont.hpp"

std::map<int, std::string> 
removeDuplicateAndTranformToMap(std::list<std::string> list, std::deque<int> deque)
{
    list.sort();
    auto it = std::unique(begin(list), end(list));
    list.erase(it, end(list));

    std::sort(begin(deque), end(deque));
    auto jt = std::unique(begin(deque), end(deque));
    deque.erase(jt, end(deque));

    std::map<int, std::string> map {};
    std::transform(begin(list), end(list), begin(deque), 
        std::inserter(map, end(map)), [](auto l, auto d){ return std::make_pair(d, l);});

    return map;
}