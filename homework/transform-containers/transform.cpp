#include "transform.hpp"

std::map<int, std::string> removeDuplicateAndTranformToMap(std::list<std::string>& li,
                std::deque<int>& dq)
{
    std::sort(dq.begin(), dq.end());
    dq.erase(std::unique(dq.begin(), dq.end()),dq.end());
    li.sort();
    li.unique();
    std::vector<std::pair<int, std::string>>tempMap(dq.size());
    std::map<int, std::string> map;
    if(li.size() < dq.size()){
        return map;
    }

    std::transform(dq.begin(), 
                   dq.end(), 
                   li.begin(),
                   tempMap.begin(),
                   [&map](auto first, auto second){
            std::pair<int, std::string> temp(first, second);
            map.insert(temp);
            return temp;
        });
    return map;
}
