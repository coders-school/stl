#include "transform.hpp"

std::map <int, std::string> removeDuplicateAndTranformToMap (
               std::list <std::string>& list, 
               std::deque <int>& deque) {
    std::map <int, std::string> m;  
    list.sort();
    list.erase (std::unique (list.begin(), list.end()), list.end());

    std::sort (deque.begin(), deque.end());
    deque.erase (std::unique (deque.begin(), deque.end()), deque.end());
    if (list.size() != deque.size()) {
        return {};
    }
    std::transform (deque.begin(), deque.end(), list.begin(), std::inserter (m, m.end()), 
        [](auto value, const auto& str){
        return make_pair (value, str); 
    });
}
