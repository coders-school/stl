#include "transformator.hpp"

#include <algorithm>
#include <iterator>
#include <utility>

std::map<int, std::string> removeDuplicateAndTranformToMap(std::list<std::string>& l, std::deque<int>& d) {
    l.sort();
    std::sort(d.begin(), d.end());

    l.erase(std::unique(l.begin(), l.end()), l.end());
    d.erase(std::unique(d.begin(), d.end()), d.end());

    std::map<int, std::string> m;

    std::transform(d.cbegin(),
                   d.cend(),
                   l.cbegin(),
                   std::inserter(m, m.end()), [](const int& key, const std::string& value) { return std::make_pair(key, value); });

    return m;
}