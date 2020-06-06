#include "sort.hpp"

#include <set>

std::deque<std::string> lengthSort(const std::forward_list<std::string>& words) {
    std::multiset<std::string, decltype(compare)> ms(compare);
    for (const auto& word : words) {
        ms.emplace(word);
    }
    std::deque<std::string> sorted(ms.begin(), ms.end());

    return sorted;
}
