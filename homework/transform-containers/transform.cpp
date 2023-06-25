#include "transform.h"
std::map<int, std::string> removeDuplicateAndTranformToMap(std::list<std::string> l, std::deque<int> d) {
    std::map<int, std::string> m;
    l.sort();
    std::sort(d.begin(), d.end());

    auto lastL = std::unique(l.begin(), l.end());
    auto lastD = std::unique(d.begin(), d.end());

    l.erase(lastL, l.end());
    d.erase(lastD, d.end());
    auto itL = l.begin();
    for (auto el : d) {
        m.insert(std::make_pair(el, *itL));
        itL++;
    }
    return m;
}
