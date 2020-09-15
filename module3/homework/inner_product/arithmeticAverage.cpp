#include "arithmeticAverage.hpp"

#include <algorithm>
#include <functional>
#include <math.h>
#include <numeric>
#include <stdexcept>
#include <vector>

double ArithmeticAverage(std::vector<int> first, std::vector<int> second) {
    std::vector<int> longer;
    std::vector<int> shorterOrEqual;

    if (first.size() == 0 && second.size() == 0) {
        throw std::invalid_argument("At least one vector should not be empty");
    }
    else if (first.size() == 0) {
        longer.reserve(second.size());
        longer = second;
        shorterOrEqual.reserve(second.size());
        shorterOrEqual = second;
    }
    else if (second.size() == 0) {
        longer.reserve(first.size());
        longer = first;
        shorterOrEqual.reserve(first.size());
        shorterOrEqual = first;
    }
    else if (first.size() >= second.size()) {
        longer.reserve(first.size());
        longer = first;
        shorterOrEqual.reserve(second.size());
        shorterOrEqual = second;
    }
    else {
        longer.reserve(second.size());
        longer = second;
        shorterOrEqual.reserve(first.size());
        shorterOrEqual = first;
    }

    auto sum = std::inner_product(longer.begin(), longer.end(), shorterOrEqual.begin(), 0,
                                 std::plus<>(), std::plus<>());

    return static_cast<double>(sum) / (longer.size() + shorterOrEqual.size());
}

double Distance(std::vector<int> first, std::vector<int> second) {
    if (first.size() == 0 || second.size() == 0) {
        throw std::invalid_argument("At least one vector should not be empty");
    }
    else if (first.size() != second.size()) {
        throw std::invalid_argument("Both vectors should be the same size");
    }

    auto sum = std::inner_product(first.begin(), first.end(), second.begin(), 0,
                                 std::plus<>(), [](const auto& x, const auto& y){
                                     return pow((y - x), 2);
                                 });

    return sqrt(static_cast<double>(sum));
}
