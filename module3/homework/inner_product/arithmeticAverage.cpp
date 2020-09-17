#include "arithmeticAverage.hpp"
#include <functional>
#include <numeric>

double ArithmeticAverage(std::vector<int> & firstVec, std::vector<int> & secVec) {
    double init = 0.0;
    return std::inner_product(firstVec.begin(), firstVec.end(), secVec.begin(), init,
                              std::plus<int>(), std::plus<int>()) / (firstVec.size() + secVec.size());
}
