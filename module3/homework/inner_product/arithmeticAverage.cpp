
#include "arithmeticAverage.hpp"
#include <functional>
#include <numeric>
#include <vector>
#include <math.h>

double ArithmeticAverage(const std::vector<int> &first_,
                         const std::vector<int> &second_) {
  return (double)std::inner_product(std::begin(first_), std::end(first_),
                                    std::begin(second_), 0, std::plus<>(),
                                    std::plus<>()) /
         (first_.size() + second_.size());
}

double OneDimensionDistance(int x1, int x2)
{
    return (double)(x2-x1)*(x2-x1);
}

double Distance(const std::vector<int> &first_,
                         const std::vector<int> &second_) {

  return (double)sqrt(std::inner_product(std::begin(first_), std::end(first_),
                                    std::begin(second_), 0, std::plus<>(),
                                    OneDimensionDistance));
}
