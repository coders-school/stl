

#include "transform.hpp"
#include <algorithm>
#include <iostream>
#include <memory>
#include <numeric>
#include <iostream>

#include <string_view>
#include <list>

std::map<int, std::string> removeDuplicateAndTranformToMap(std::list<std::string> str, std::deque<int> deq)
{
    std::map<int, std::string> p ;

    str.sort();
    str.unique();
    std::sort(deq.begin(), deq.end());
    deq.erase(std::unique(deq.begin(), deq.end()), deq.end());
    auto it = deq.begin();
    auto it2 = str.begin();
    for(size_t i = 0; i < str.size(); i++)
    {
        p.insert({*it, *it2});
        it++;
        it2++;
    }
    return p;
}
