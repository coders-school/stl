#include "sort.hpp"
#include <deque>
#include <forward_list>
#include <string>
#include <algorithm>

std::deque<std::string> lengthSort(const std::forward_list<std::string>& stringsList) {
    std::deque<std::string> stringsDeque;
    for (const auto& string : stringsList) {
        stringsDeque.push_back(string);
    }
    std::sort(stringsDeque.begin(), stringsDeque.end(),
              [](const std::string& first, const std::string& second) {
                  if (first.size() == second.size()) {
                      return first < second;
                  }
                  return first.size() < second.size();
              });
    return stringsDeque;
}
