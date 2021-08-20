#include "arithmeticAverage.hpp"
#include <functional>
#include <numeric>
#include <stdexcept>
#include <cmath>

double ArithmeticAverage(const std::vector<int> &first,
                         const std::vector<int> &second) {
  double sum = std::reduce(first.cbegin(), first.cend(), 0) +
             std::reduce(second.cbegin(), second.cend(), 0);
  return sum / (first.size() + second.size());
}

double Distance(const std::vector<int> &first, const std::vector<int> &second) {
  if (first.size() != second.size()) {
    throw std::logic_error{"vectors' sizes differ"};
  }

    auto diffed_sum = std::transform_reduce(
      first.cbegin(), first.cend(), second.cbegin(), 0,
      std::plus{}, [](const int num1, const int num2) {
        return (num1 - num2) * (num1 - num2);
      });
    return std::sqrt(diffed_sum);
}