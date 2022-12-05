#include "transform.hpp"

std::map<int, std::string> removeDuplicateAndTranformToMap(std::list<std::string> lis, std::deque<int> deq) {
    std::map<int,std::string> map {};
    std::vector<std::string> vec {};

    lis.sort();
    auto word = std::unique(lis.begin(), lis.end());
    lis.erase(word, lis.end());
    std::sort(deq.begin(), deq.end());
    auto number = std::unique(deq.begin(), deq.end());
    deq.erase(number, deq.end());
    for(auto n : lis) {
        vec.push_back(n);
    }
    std::transform(deq.begin(), deq.end(), vec.begin(), std::inserter(map, map.end()),
                  [](const auto i,const auto s) {return std::make_pair(i, s);});
    return map;

}