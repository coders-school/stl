#include "transformation.hpp"


std::map<int, std::string> removeDuplicateAndTransformToMap(std::list<std::string> listCont,std::deque<int> deqCont)
{
listCont.sort();
listCont.erase(std::unique(listCont.begin(),listCont.end()),listCont.end());
std::sort(deqCont.begin(),deqCont.end());
deqCont.erase(std::unique(deqCont.begin(),deqCont.end()),deqCont.end());
    std::map<int, std::string> newMap;
    std::transform(deqCont.begin(), deqCont.end(),
    listCont.begin(), std::inserter(newMap,newMap.end()),
    [](auto k, auto& v) { return std::make_pair(k, v); });
return newMap;
};