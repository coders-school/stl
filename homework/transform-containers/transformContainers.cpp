#include "transformContainers.hpp"
#include <algorithm>
#include <iterator>
#include <functional>

// template <typename T>
// void removeDuplicates(T& container) {
//     // std::sort(container.begin(), container.end());
// }

std::map<int, std::string> removeDuplicateAndTranformToMap(std::list<std::string> list, std::deque<int> deque) {

    // std::sort(list.begin(), list.end(), [](auto first, auto second){
    //     return std::lexicographical_compare(first.begin(), first.end(), second.begin(), second.end());
    // });
    list.sort();
    std::sort(deque.begin(), deque.end());
    
    list.erase(std::unique(list.begin(), list.end()), list.end());
    deque.erase(std::unique(deque.begin(), deque.end()), deque.end());

    std::map<int, std::string> resultMap;
    std::map<int, std::string> resultMap2;
    if (list.size() == deque.size()) {

        // auto dequeIt = deque.begin();
        // auto  listIt = list.begin();
        // for (; dequeIt != deque.end(); dequeIt++, listIt++) {
        //     resultMap.insert({*dequeIt, *listIt});
        // }

        // std::transform(deque.begin(), deque.end(), list.begin(), resultMap2.begin(), [](auto first, auto second) {
        std::transform(deque.begin(), deque.end(), list.begin(), std::inserter(resultMap, resultMap.end()), [](int first, std::string second) {
            return std::make_pair(first, second);
        });
    }
    
    return resultMap;
}