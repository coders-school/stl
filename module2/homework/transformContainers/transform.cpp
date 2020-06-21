#include "transform.hpp"

#include <algorithm>

std::map<int, std::string> removeDuplicateAndTranformToMap(std::list<std::string> List, 
                                                            std::deque<int> Deque){
    std::map<int, std::string> Map;
    List.sort();
    std::sort(Deque.begin(), Deque.end());
    List.unique();
    auto toRemove = std::unique(Deque.begin(), Deque.end());
    Deque.erase(toRemove, Deque.end());
    std::transform(List.cbegin(), List.cend(), Deque.cbegin(), std::inserter(Map, Map.end()), [](const auto& String, auto Number){
        return std::make_pair(Number, String);
    });

    return Map;
    }
