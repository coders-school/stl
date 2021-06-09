#include "sort.hpp"
#include <algorithm>

std::deque<std::string> lengthSort(const std::forward_list<std::string>& strings) {
    std::deque<std::string> deq{ strings.begin(), strings.end() };
    std::sort(deq.begin(), deq.end(),
              [](const std::string& lhs, const std::string& rhs) {
                  return lhs.size() == rhs.size() ?
                         lhs < rhs :
                         lhs.size() < rhs.size();
              });

    return deq;
}
