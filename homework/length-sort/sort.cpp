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
  std::vector<std::string> vec{};
  std::deque<std::string> deq{};
  for (const auto &it : list) {
    // std::cout << it << "\n";
    vec.push_back(it);
  };

  std::sort(vec.begin(), vec.end(),[](const auto& a, const auto&b){return a.size()>b.size();});

  for (const auto &it : vec) {

    // std::cout << it << "\n";
    deq.push_back(it);
  };

  // std::deque<std::string> deq{"dupa"};
  return deq;
};