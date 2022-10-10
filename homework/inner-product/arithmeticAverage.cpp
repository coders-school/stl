#include <numeric>
#include "arithmeticAverage.hpp"

double ArithmeticAverage(const std::vector<int>& first, const std::vector<int>& second) {
    if (first.empty() && second.empty()) {
        return 0.0;
    }

    double average = std::reduce(first.cbegin(), first.cend(),
                                 std::reduce(second.cbegin(), second.cend(), 0));
    return average / static_cast<double>(first.size() + second.size());
}

double Distance(const std::vector<int>& first, const std::vector<int>& second) {
    return 0;
}
