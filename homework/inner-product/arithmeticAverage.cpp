#include "arithmeticAverage.hpp"

struct Sum {
  void operator()(int n) { sum += n; }
  int sum{0};
};

double arithmeticAverage(const std::vector<int> &first,
                         const std::vector<int> &second) {
  std::vector<int> AB;
  AB.reserve(first.size() + second.size());
  AB.insert(AB.end(), first.begin(), first.end());
  AB.insert(AB.end(), second.begin(), second.end());
  Sum sum = std::for_each(AB.begin(), AB.end(), Sum());
  return sum.sum / AB.size();
}