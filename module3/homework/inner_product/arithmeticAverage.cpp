#include "arithmeticAverage.hpp"
#include <functional>
#include <numeric>

double ArithmeticAverage(const std::vector<int> & firstVec, const std::vector<int> & secVec) {
    double init = 0.0;
    return std::inner_product(firstVec.begin(), firstVec.end(), secVec.begin(), init,
                              std::plus<int>(), std::plus<int>()) / (firstVec.size() + secVec.size());
}
