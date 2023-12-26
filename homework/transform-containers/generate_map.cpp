#include "generate_map.hpp"

#include <algorithm>
#include <iterator>
#include <utility>
#include <vector>

std::map<int, std::string>
    removeDuplicateAndTranformToMap(std::list<std::string> l, std::deque<int> d) {
    std::sort(d.begin(), d.end());
    l.sort();
    d.erase(std::unique(d.begin(), d.end()), d.end());
    l.unique();
    std::vector<std::pair<int, std::string>> temp;
    std::map<int, std::string> result;
    std::transform(d.cbegin(),
                   d.cend(),
                   l.cbegin(),
                   std::back_inserter(temp),
                   [](const auto& item1, const auto& item2) {
                       return std::make_pair(item1, item2);
                   });
    std::for_each(temp.cbegin(), temp.cend(), [&result](const auto& elem) {
        result[elem.first] = elem.second;
    });
    return result;
}
