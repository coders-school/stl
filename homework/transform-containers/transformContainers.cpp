#include "transformContainers.hpp"

#include <algorithm>

std::map<int, std::string> removeDuplicateAndTranformToMap(std::list<std::string>& list, std::deque<int>& deq) {
    list.sort();
    list.unique();
    std::sort(begin(deq), end(deq));

    deq.erase(std::unique(begin(deq), end(deq)), end(deq));

    std::map<int, std::string> map;
    std::transform( begin(deq), 
                    end(deq), 
                    begin(list), 
                    std::inserter(map, begin(map)),
                    [](const auto number, const auto& word) {
                        return make_pair(number, word);
                    });
    
    return map;
}
