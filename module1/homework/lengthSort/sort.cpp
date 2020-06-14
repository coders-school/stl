#include "sort.hpp"

#include <algorithm>

std::deque<std::string> lengthSort(const std::forward_list<std::string>& sortMe) {
    std::deque<std::string> result(sortMe.begin(), sortMe.end());
    std::sort(begin(result),
              end(result),
              [](const std::string& lhs, const std::string& rhs) {
                  if (lhs.length() == rhs.length()) {
                      return lhs < rhs;
                  }

                  return lhs.length() < rhs.length();
              });

    return result;
}
