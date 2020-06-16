#include "transform.hpp"

#include <algorithm>

std::map<int, std::string> removeDuplicateAndTranformToMap(
        const std::list<std::string>& list,
        const std::deque<int>& deque) {

    std::map<int, std::string> uniques;
    std::list<std::string> uniq(list);

    uniq.sort();
    uniq.erase(std::unique(uniq.begin(),
                           uniq.end()),
               uniq.end());
    std::transform(uniq.begin(),
                   uniq.end(),
                   deque.begin(),
                   std::inserter(uniques, uniques.end()),
                   [](const std::string& s, const int i) {
                       return std::make_pair(i, s);
                   });

    return uniques;
}
