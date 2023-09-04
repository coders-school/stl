#include "mapMaking.hpp"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <unordered_set>

std::map<int, std::string> removeDuplicateAndTranformToMap(std::list<std::string> list, std::deque<int> deque) {
    std::map<int, std::string> res{};
    list.sort();
    list.unique();
    std::unordered_set<int> uniqueNumbers{};
    std::sort(deque.begin(), deque.end());
    for (auto itr = deque.begin(); itr != deque.end();) {
        auto ins = uniqueNumbers.insert(*itr);
        if (!ins.second) {
            itr = deque.erase(itr);
        } else {
            ++itr;
        }
    }

    std::transform(deque.begin(), deque.end(), list.begin(),
                   std::inserter(res, res.begin()),
                   [](int key, const std::string& value) {
                       return std::make_pair(key, value);
                   });

    return res;
}