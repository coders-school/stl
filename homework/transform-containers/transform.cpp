
#include "transform.hpp"
#include <algorithm>
#include <iostream>

void removeDuplicate(std::list<std::string>& lis) {
    lis.sort();
    lis.erase(std::unique(lis.begin(), lis.end()), lis.end());
}

void removeDuplicate(std::deque<int>& deq) {
    std::sort(deq.begin(), deq.end());
    deq.erase(std::unique(deq.begin(), deq.end()), deq.end());
}

void TranformToMap(std::list<std::string>& lis, std::deque<int>& deq, std::map<int, std::string>& map) {
    if (lis.size() != deq.size()) {
        std::cerr << "Containers must be of the same size";
    } else {
        //https://stackoverflow.com/questions/46948042/using-stdtransform-to-convert-a-stdvectorstructkey-val-into-a-stdmap
        std::transform(deq.begin(), deq.end(), lis.begin(), std::inserter(map, map.end()),
                       [](auto key, auto value) { return std::make_pair(key, value); });
    };
}

std::map<int, std::string> removeDuplicateAndTranformToMap(std::list<std::string>& lis, std::deque<int>& deq) {
    std::map<int, std::string> map;
    removeDuplicate(lis);
    removeDuplicate(deq);
    TranformToMap(lis, deq, map);
    return map;
}