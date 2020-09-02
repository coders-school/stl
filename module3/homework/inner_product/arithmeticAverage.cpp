#include "arithmeticAverage.hpp"

#include <cmath>
#include <numeric>

double ArithmeticAverage(std::vector<int> lhs, std::vector<int> rhs) {
    if (lhs.size() != rhs.size()) {
        return 0;
    }
    auto sum = std::inner_product(begin(lhs), end(lhs), begin(rhs), 0, std::plus<int>(), std::plus<int>());
    return static_cast<double>(sum) / (lhs.size() + rhs.size());
}

double Distance(std::vector<int> lhs, std::vector<int> rhs) {
    if (lhs.size() != rhs.size()) {
        return -1;
    }
    auto sumOfPowers = std::inner_product(begin(lhs), end(lhs), begin(rhs), 0, std::plus<int>(), [](int lhs, int rhs) {
        return (rhs - lhs) * (rhs - lhs);
    });
    return sqrt(sumOfPowers);
}
