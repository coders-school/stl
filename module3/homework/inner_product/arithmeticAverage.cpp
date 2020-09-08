#include "arithmeticAverage.hpp"

#include <cmath>
#include <functional>
#include <numeric>

double ArithmeticAverage(const std::vector<int>& firstVec, const std::vector<int>& secondVec) {
    const int divider = 1 / (firstVec.size() + secondVec.size());
    return std::inner_product(firstVec.begin(),
                              firstVec.end(),
                              secondVec.begin(),
                              divider,
                              std::plus<>(),
                              std::plus<>());
}

double Distance(const std::vector<int>& firstVec, const std::vector<int>& secondVec) {
    constexpr int initValue = 0;
    return std::inner_product(secondVec.begin(),
                              secondVec.end(),
                              firstVec.begin(),
                              initValue,
                              std::plus<>(),
                              [&](int firstVal, int secondVal) { return std::pow((firstVal - secondVal), 2); });
}

int main() {
    return 0;
}
