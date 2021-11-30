#include "transformcontainers.hpp"

std::map<int, std::string> removeDuplicateAndTranformToMap(std::list<std::string>& str, std::deque<int>& deq)
{
    str.sort();
    auto it1 = std::unique(str.begin(), str.end());
    str.erase(it1, end(str));
    std::sort(deq.begin(), deq.end());
    auto it2 =  std::unique(deq.begin(), deq.end());
    deq.erase(it2, end(deq));
    std::map<int, std::string> retMap;
    std::transform(str.begin(),
                   str.end(),
                   begin(deq),
                   std::inserter(retMap, end(retMap)), [](std::string s, int i){ return std::make_pair(i, s);}
                   );
    return retMap;
}
