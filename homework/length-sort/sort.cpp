#include <algorithm>

#include "sort.hpp"

bool sortBy(const std::string& j, const std::string& k) {
    if (j.size() == k.size()) {
        return j < k;
    } else {
        return j.size() < k.size();
    }
}

std::deque<std::string> lengthSort(std::forward_list<std::string>& tab) {
    std::deque<std::string> dTab;
    for (auto& v : tab) {
        dTab.push_back(v);
    }
    std::sort(dTab.begin(), dTab.end(), sortBy);
    return dTab;
}
