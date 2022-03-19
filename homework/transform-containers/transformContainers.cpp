#include "transformContainers.hpp"

std::map<int, std::string> removeDuplicateAndTranformToMap(std::list<std::string>& list, std::deque<int>& deque) {
    std::map<int, std::string> output;
    // remove duplicates from list
    list.sort();
    list.unique();
    // remove duplicates from deque
    sort(deque.begin(), deque.end());
    deque.erase(unique(deque.begin(), deque.end()), deque.end());
    auto it = list.begin();
    // convert to map
    for(auto i = 0; i < list.size(); ++i) {
        output.insert(std::make_pair(deque.at(i), *it));
        std::advance(it, 1);
    }
    
    // ???
    // profit
    return output;
}
