#include "arithmeticAverage.hpp"
#include <cmath>
#include <functional>
#include <numeric>

double ArithmeticAverage(const std::vector<int> & firstVec, const std::vector<int> & secVec) {
    double init = 0.0;
    return std::inner_product(firstVec.begin(), firstVec.end(), secVec.begin(), init,
                              std::plus<int>(), std::plus<int>()) / (firstVec.size() + secVec.size());
}

double Distance(const std::vector<int> & pointA, const std::vector<int> & pointB) {
    double init = 0.0;
    return std::sqrt(std::inner_product(pointA.begin(), pointA.end(), pointB.begin(), init,
                                        std::plus<int>(), [](int first, int second){
                                            return std::pow(first - second, 2);}));
}