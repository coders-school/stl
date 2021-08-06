#include "transformer.hpp"
#include <algorithm>
#include <deque>
#include <list>
#include <map>
#include <stdexcept>
#include <string>
#include <utility>

std::map<int, std::string> removeDuplicateAndTranformToMap(std::list<std::string> lst, std::deque<int> deq) {
    lst.sort();
    std::sort(deq.begin(), deq.end());
    lst.erase(std::unique(lst.begin(), lst.end()), lst.end());
    deq.erase(std::unique(deq.begin(), deq.end()), deq.end());
    if (lst.size() != deq.size()) {
        throw std::invalid_argument("Containers don't have equal number of unique elements");
    }
    std::map<int, std::string> result;
    std::transform(deq.cbegin(), deq.cend(), lst.cbegin(), std::inserter(result, result.end()),
                   [](auto number, auto str) { return std::make_pair(number, str); });
    return result;
}
