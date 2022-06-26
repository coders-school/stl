#include "arithmeticAverage.hpp"

struct Sum {
  void operator()(int n) { sum += n; }
  int sum{0};
};

double ArithmeticAverage(const std::vector<int> &first,
                         const std::vector<int> &second) {
  std::vector<int> AB;
  AB.reserve(first.size() + second.size());
  AB.insert(AB.end(), first.begin(), first.end());
  AB.insert(AB.end(), second.begin(), second.end());
  Sum sum = std::for_each(AB.begin(), AB.end(), Sum());
  return sum.sum / AB.size();
}

double Distance(const std::vector<int> &first, const std::vector<int> &second) {
  int n = first.size();
  std::vector<int> tmp;
  for (size_t i = 0; i < n; i++) {
    tmp.push_back(pow(first[i] - second[i], 2));
  }
  return sqrt(accumulate(tmp.begin(), tmp.end(), 0));
}