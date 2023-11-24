#include "transform.hpp"

std::map<int, std::string> removeDuplicateAndTranformToMap(std::list<std::string> l, std::deque<int> d) {
    std::map<int, std::string> m;
    std::set<int> s1{d.begin(), d.end()};
    std::set<std::string> s2{l.begin(), l.end()};
    
    std::transform(s1.begin(), s1.end(), s2.begin(), std::inserter(m, m.begin()),
                   [](const auto &key, const auto &value) {
                       return std::make_pair(key, value);
                   });
    return m;
}
