#include "sort.hpp"
#include <algorithm>
#include <deque>
#include <forward_list>
#include <string>
#include <tuple>

std::deque<std::string> lengthSort(const std::forward_list<std::string>& input_forwardlist) {
    std::deque<std::string> output_deq(input_forwardlist.begin(), input_forwardlist.end());

    std::sort(output_deq.begin(), output_deq.end(),
              [](const std::string& first, const std::string& second) {
                  return std::tuple(first.size(), first) < std::tuple(second.size(), second);
              });

    return output_deq;
}
