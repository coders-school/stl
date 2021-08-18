#include "transform.h"

void removeDuplicate(std::list<std::string>& li, std::deque<int>& dq)
{
    std::sort(dq.begin(), dq.end());
    dq.erase(std::unique(dq.begin(), dq.end()),dq.end());
    li.sort();
    li.unique();
}

std::map<int, std::string> removeDuplicateAndTranformToMap(std::list<std::string>& li, std::deque<int>& dq)
{
    removeDuplicate(li, dq);
    std::map<int, std::string> map;
    if(li.size() < dq.size()){
        return map;
    }
    std::transform(dq.begin(), dq.end(), li.begin(), std::inserter(map, map.end()),
                   [](auto key, auto value){return std::make_pair(key, value);});
    return map;
}