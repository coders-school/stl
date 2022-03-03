#include "transformContainers.hpp"

resultMap removeDuplicateAndTranformToMap(inList& list, inDeq& deque){
    // std::sort(list.begin(),list.end());
    list.sort();
    std::sort(deque.begin(),deque.end());
    list.erase(std::unique(list.begin(),list.end()),list.end());
    deque.erase(std::unique(deque.begin(),deque.end()),deque.end());
  
    resultMap map;

    auto f = [](const std::string & s, const int & in){
        return std::make_pair(in,s);
    };
    std::transform(list.begin(),
                   list.end(),
                   deque.begin(),
                   std::inserter(map,map.begin()),
                   f);
    return map;
}