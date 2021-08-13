#include "transform_containers.h"

std::map<int, std::string> removeDuplicateAndTranformToMap(std::list<std::string>& list, std::deque<int>& deque) {
    std::map<int, std::string> result;
    list.sort();
    list.erase(std::unique(list.begin(), list.end()), list.end());
    std::sort(deque.begin(), deque.end());
    deque.erase(std::unique(deque.begin(), deque.end()), deque.end());
    std::transform(deque.begin(), deque.end(), list.begin(), std::inserter(result, result.end()), [](auto a, auto b){
        return std::make_pair(a, b);
    });
    return result;
}
