#include "transform.hpp"

std::map<int, std::string> removeDuplicateAndTranformToMap(std::list<std::string>& li,
                std::deque<int>& dq)
{
    std::sort(dq.begin(), dq.end());
    dq.erase(std::unique(dq.begin(), dq.end()),dq.end());
    li.sort();
    li.unique();
    std::vector<std::pair<int, std::string>>tempMap;
    std::map<int, std::string> map;

    std::transform(dq.begin(), 
                   dq.end(), 
                   li.begin(), 
                   std::back_inserter(tempMap),
                   [&map](auto first, auto second){
            std::pair<int, std::string> temp(first, second);
            map.insert(temp);
            return temp;
        });
    return map;
}
