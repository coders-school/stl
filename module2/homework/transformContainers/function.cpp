#include "function.hpp"

#include <algorithm>
#include <iterator>

std::map<int, std::string> removeDuplicateAndTranformToMap(std::list<std::string> list, std::deque<int> deque) {
    std::map<int, std::string> result;

    list.sort();
    list.unique();
    std::sort(begin(deque), end(deque));
    deque.erase(std::unique(begin(deque), end(deque)), end(deque));

    std::transform(begin(deque), end(deque), begin(list), std::inserter(result, end(result)), [&](auto fromDeque, auto& fromList){
        return std::make_pair(fromDeque, fromList);
    });

    return result;
}
