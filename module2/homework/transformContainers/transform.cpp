#include "transform.hpp"

#include <algorithm>
#include <iterator>
#include <utility>

std::map<int, std::string> removeDuplicateAndTranformToMap(std::list<std::string> stringList, std::deque<int> intDeque) {
    stringList.sort();
    stringList.erase(std::unique(stringList.begin(), stringList.end()));
    std::sort(intDeque.begin(), intDeque.end());
    intDeque.erase(std::unique(intDeque.begin(), intDeque.end()));

    std::map<int, std::string> map;

    std::transform(intDeque.begin(),
                   intDeque.end(),
                   stringList.begin(),
                   std::inserter(map, map.end()),
                   [](const auto& dequeElem, const auto& listElem) {
                       return std::make_pair(dequeElem, listElem);
                   });

    return map;
}

int main() {
    return 0;
}
