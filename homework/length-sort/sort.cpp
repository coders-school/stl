#include "sort.hpp"
#include <algorithm>
#include <deque>
#include <forward_list>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

std::deque<std::string> lengthSort(std::forward_list<std::string> list) {
  list.sort();
  std::deque<std::string> deq{};

  for (const auto &it : list) {
    deq.push_back(it);
  };

  std::sort(deq.begin(), deq.end(),
            [](const auto &a, const auto &b) { return a.size() < b.size(); });
  return deq;
};